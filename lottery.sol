// Solidity smart contract for lottery
// "SPDX-License-Identifier: GPL -3.0" 
pragma solidity >=0.5.0 <0.9.0;     // Including version of solidity

// Contract is necessary for each smart contract e.g. classes in OOP 
contract Lottery{
    address public manager;
    // making a dynamic array 
    address payable[] public participants;        // payable will be used for that account which will be the winner and whom we'll send the winning amount

    // giving control to manager
    constructor(){
        // Global Variable
        manager = msg.sender;   // After deploying/compiling, the address of contract will be handled to manager   
    }

    // Fuction to recieve transaction from the participants
    // recieve can only be used once in the prgram 
    receive() external payable{
        require(msg.value == 2 ether); // if this is true, only that will allow next statement to execute, if-else
        participants.push(payable(msg.sender));
    }

    function getBalance() public view returns(uint){
        require(msg.sender==manager); // Only manager can see all amount of balance
        return address(this).balance;
    }

    // To select winner on random basis
    function random() public view returns(uint){
        // keccak is basically used to create a random number based on some input level
        return uint(keccak256(abi.encodePacked(block.difficulty, block.timestamp, participants.length)));      // unit is being used for converting the hexadecimal to int value
    }

    // Selecting the winner 
    function selectWinner() public /* view returns(address) */ {
        require(msg.sender==manager);
        require(participants.length >= 3);
        
        address payable winner;
        uint r = random();
        uint index = r % participants.length;

        winner = participants[index];
        
        // return winner;

        winner.transfer(getBalance());
        participants = new address payable[](0);
    }
}



// SPDX-License-Identifier: GPL-3.0


/**
 * We want to ensure that we use at least v0.8 of the Solidity compiler
 * where overflows are checked by default, so we no longer need a SafeMath
 * library - see https://docs.soliditylang.org/en/v0.8.6/control-structures.html#checked-or-unchecked-arithmetic
 */
pragma solidity >=0.8.0 <0.9.0;


/** 
 * @title NFT
 * @dev Implements an ERC721 token, see https://eips.ethereum.org/EIPS/eip-721
 */

contract NFT {

    event Transfer(
        address indexed from,
        address indexed to,
        uint256 indexed tokenID
    );

    event Approval(
        address indexed owner,
        address indexed spender,
        uint256 indexed tokenID
    );

    event ApprovalForAll(
        address indexed owner,
        address indexed operator,
        bool approved
    );

    /// magic value returned by a contract
    /// implement ERC721Receiver
    bytes4 private constant magicValue = 0x150b7a02;

    /// Interface IDs
    bytes4 private constant erc165InterfaceID = 0x01ffc9a7;
    bytes4 private constant erc721InterfaceID = 0x80ac58cd;
    bytes4 private constant erc721metadataID = 0x5b5e139f;


    /// The owner of the contract
    address private _contractOwner;

    /// The base URI
    string private _baseURI;

    /// The owner of each token
    mapping (uint256 => address) private _ownerOf;

    /// The balance of NFT for each address
    mapping (address => uint256) private _balances;

    /// Keep track of approvals per tokenID
    mapping (uint256 => address) private _approvals; 

    /// Keep track of operators
    mapping (address => mapping(address => bool)) private _isOperatorFor;

    /// Name and symbol of the contract
    string private constant _name = "Non-fungible token";
    string private constant _symbol = "MNFT";


    /// Messages
    string private constant _requiresOwner = "Sender not contract owner";
    string private constant _invalidTokenID = "Invalid token ID";
    string private constant _invalidAddress = "Address 0 is not valid";
    string private constant _senderNotAuthorized = "Sender not authorized";

    ///
    /// Constructor - remember who the contract owner is and assign initial balance
    /// Also set the baseURI
    ///
    constructor(string memory baseURI)  {
        _baseURI = baseURI;
        _contractOwner = msg.sender;
    }

    /// Modifier to check that the sender of the msg is the 
    /// contract owner

    modifier isContractOwner() {
        require(msg.sender == _contractOwner, _requiresOwner);
        _;
    }

    /// Modifier to check that a token ID is valid
    modifier isValidToken(uint256 _tokenID) {
        require(_ownerOf[_tokenID] != address(0), _invalidTokenID);
        _;
    }

    /// Modifier to check that an address is valid
    modifier isValidAddress(address _address) {
        require(_address != address(0), _invalidAddress);
        _;
    }

    /// Return the count of all NFTs assigned to an owner. Throw
    /// if the queried address is 0
    /// @param owner An address for whom to query the balance
    /// @return The number of NFTs owned by `owner`, possibly zero
    function balanceOf(address owner) external view isValidAddress(owner) returns (uint256) {
        return _balances[owner];
    }

    /// Return the owner of an NFT. If the result is the zero address,
    /// the token is considered invalid and we throw
    /// @param tokenID The identifier for an NFT
    /// @return The address of the owner of the NFT
    function ownerOf(uint256 tokenID) external view isValidToken(tokenID) returns (address)  {
        return _ownerOf[tokenID];
    }

    /// Mint a token. This is a non-standard extension.
    function _mint(uint256 tokenID) external isContractOwner {
        require(_ownerOf[tokenID] == address(0), "Token already exists");
        _balances[_contractOwner] +=1;
        _ownerOf[tokenID] = _contractOwner;
        /// Emit event
        emit Transfer(address(0), _contractOwner, tokenID);
    }

    /// Burn a token. Do nothing if the token does not exist instead
    /// of reverting, so that we can use this to make sure that a token
    /// does not exist. 
    /// IMPORTANT: the contract owner can burn EVERY token, regardless
    /// of who the current owner is - this is nothing you would accept
    /// for a real NFT. DO NOT DO THIS IN PRODUCTION
    function _burn(uint256 tokenID) external isContractOwner {
        address owner = _ownerOf[tokenID];
        if (owner == address(0)) {
            return;
        }
        _balances[owner] -=1;
        _ownerOf[tokenID] = address(0);
        _approvals[tokenID] = address(0);
        /// Emit event
        emit Transfer(owner, address(0), tokenID);
    }


    /// Transfer ownership of an NFT. Throws unless `msg.sender` is the current owner, an authorized
    ///  operator, or the approved address for this NFT. Throws if `from` is
    ///  not the current owner. Throws if `to` is the zero address. Throws if
    ///  `tokenId` is not a valid NFT.
    /// @param from The current owner of the NFT
    /// @param to The new owner
    /// @param tokenID The NFT to transfer
    function transferFrom(address from, address to, uint256 tokenID) external payable {
        _doTransferFrom(from, to, tokenID);
    }

    function _doTransferFrom(address from, address to, uint256 tokenID) private isValidToken(tokenID) isValidAddress(to) {
        address currentOwner = _ownerOf[tokenID];
        require(from == currentOwner, "From not current owner");
        bool authorized = (msg.sender == from) 
                            || (_approvals[tokenID] == msg.sender) 
                            || (_isOperatorFor[currentOwner][msg.sender]);
        require(authorized, _senderNotAuthorized);
        _balances[currentOwner]-=1;
        _balances[to]+=1;
        _ownerOf[tokenID] = to;
        _approvals[tokenID] = address(0);
        /// Emit transfer event. My interpretation of the standard is that this event
        /// is sufficient to also indicate that the approval has been reset. This is in line
        /// with the 0xcert implementation (https://github.com/0xcert/ethereum-erc721/blob/master/src/contracts/tokens/nf-token.sol)
        /// but deviates from the OpenZeppelin implementation, see, however, also this issue
        /// https://github.com/OpenZeppelin/openzeppelin-contracts/issues/1038
        /// which seems to support this point of view
        emit Transfer(from, to, tokenID);
    }

    function _isContract(address addr) private view returns (bool){
        uint32 size;
        assembly {
            size := extcodesize(addr)
        }
        return (size > 0);
    }


    function _invokeOnERC721Received(address to, address operator, address from, uint256 tokenID, bytes memory data) private {
        if (_isContract(to)) {
            ERC721TokenReceiver erc721Receiver = ERC721TokenReceiver(to);
            bytes4 retval = erc721Receiver.onERC721Received(operator, from, tokenID, data);
            require(retval == magicValue, "Did not return magic value");
        }
    }

    /// Transfers the ownership of an NFT from one address to another address
    /// Throws if the sender is not authorized or if from is not the current owner
    ///  Throws if `to` is the zero address. Throws if
    ///  `tokenID` is not a valid NFT. When a transfer is complete, this function
    ///  checks if `to` is a smart contract (code size > 0). If so, it calls
    ///  `onERC721Received` on `to` and throws if the return value is not
    ///  `bytes4(keccak256("onERC721Received(address,address,uint256,bytes)"))`.
    /// @param from The current owner of the NFT
    /// @param to The new owner
    /// @param tokenID The NFT to transfer
    /// @param data Additional data with no specified format, sent in call to `_to`
    function safeTransferFrom(address from, address to, uint256 tokenID, bytes memory data) external payable {
        _doTransferFrom(from, to, tokenID);
        _invokeOnERC721Received(to, msg.sender, from, tokenID, data);
    }

    /// This works identically to the other function with an extra data parameter,
    /// except this function just sets data to "".
    /// @param from The current owner of the NFT
    /// @param to The new owner
    /// @param tokenID The NFT to transfer
    function safeTransferFrom(address from, address to, uint256 tokenID) external payable {
        _doTransferFrom(from, to, tokenID);
        _invokeOnERC721Received(to, msg.sender, from, tokenID, bytes(""));
    }

    /// Change or reaffirm the approved address for an NFT
    /// The zero address indicates there is no approved address.
    /// Throws unless `msg.sender` is the current NFT owner, or an authorized
    /// operator of the current owner.
    /// @param approved The new approved NFT controller
    /// @param tokenID The NFT to approve
    function approve(address approved, uint256 tokenID) external payable isValidToken(tokenID) {
        address currentOwner = _ownerOf[tokenID];
        bool authorized = (msg.sender == currentOwner) 
                           || (_isOperatorFor[currentOwner][msg.sender]);
        require(authorized, _senderNotAuthorized);
        _approvals[tokenID] = approved;
        emit Approval(_ownerOf[tokenID], approved, tokenID);
    }

    /// Get the approved address for a single NFT
    /// Throws if `tokenID` is not a valid NFT.
    /// @param tokenID The NFT to find the approved address for
    /// @return The approved address for this NFT, or the zero address if there is none
    function getApproved(uint256 tokenID) external view isValidToken(tokenID) returns (address) {
        return _approvals[tokenID];
    }

    /// Enable or disable approval for a third party ("operator") to manage
    /// all of `msg.sender`'s assets
    /// Emits the ApprovalForAll event. The contract MUST allow
    /// multiple operators per owner.
    /// @param operator Address to add to the set of authorized operators
    /// @param approved True if the operator is approved, false to revoke approval
    function setApprovalForAll(address operator, bool approved) external {
        _isOperatorFor[msg.sender][operator] = approved;
        emit ApprovalForAll(msg.sender, operator, approved);
    }

    /// Query if an address is an authorized operator for another address
    /// @param owner The address that owns the NFTs
    /// @param operator The address that acts on behalf of the owner
    /// @return True if `operator` is an approved operator for `owner`, false otherwise
    function isApprovedForAll(address owner, address operator) external view returns (bool) {
        return _isOperatorFor[owner][operator];
    }

    /// ERC165 - supportsInterface implementation
    /// see https://github.com/ethereum/EIPs/blob/master/EIPS/eip-165.md
    function supportsInterface(bytes4 interfaceID) external pure returns (bool) {
        return (interfaceID == erc165InterfaceID) 
                || (interfaceID == erc721InterfaceID)
                || (interfaceID == erc721metadataID);
    }

    /// A descriptive name for a collection of NFTs in this contract
    /// part of the ERC721 Metadata extension
    function name() external pure returns (string memory) {
        return _name;
    }

    /// An abbreviated name for NFTs in this contract
    /// part of the ERC721 Metadata extension
    function symbol() external pure returns (string memory) {
        return _symbol;
    }

    function _toString(uint256 value) private pure returns (string memory) {
        /// taken from OpenZeppelin 
        /// https://github.com/OpenZeppelin/openzeppelin-contracts/blob/master/contracts/utils/Strings.sol
        /// MIT licensed
        if (value == 0) {
            return "0";
        }
        uint256 temp = value;
        uint256 digits;
        while (temp != 0) {
            digits++;
            temp /= 10;
        }
        bytes memory buffer = new bytes(digits);
        while (value != 0) {
            digits -= 1;
            buffer[digits] = bytes1(uint8(48 + uint256(value % 10)));
            value /= 10;
        }
        return string(buffer);
    }    

    /// A distinct Uniform Resource Identifier (URI) for a given asset.
    /// Throws if `tokenID` is not a valid NFT. 
    function tokenURI(uint256 tokenID) external view isValidToken(tokenID) returns (string memory) {
        return string(abi.encodePacked(_baseURI, _toString(tokenID)));
    }

    /// A non-standard function to retrieve the baseURI
    function _getBaseURI() external view returns (string memory) {
        return _baseURI;
    }
}
/**
 * ERC-721 interface for accepting safe transfers.
 * See https://github.com/ethereum/EIPs/blob/master/EIPS/eip-721.md.
 */
interface ERC721TokenReceiver
{
  function onERC721Received(address, address, uint256, bytes calldata) external returns(bytes4);
}

// SPDX-License-Identifier: MIT

// Amended by HashLips
/**
    !Disclaimer!
    These contracts have been used to create tutorials,
    and was created for the purpose to teach people
    how to create smart contracts on the blockchain.
    please review this code on your own before using any of
    the following code for production.
    HashLips will not be liable in any way if for the use 
    of the code. That being said, the code has been tested 
    to the best of the developers' knowledge to work as intended.
*/

pragma solidity >=0.7.0 <0.9.0;

import "@openzeppelin/contracts/token/ERC721/extensions/ERC721Enumerable.sol";
import "@openzeppelin/contracts/access/Ownable.sol";

contract NFT is ERC721Enumerable, Ownable {
  using Strings for uint256;

  string baseURI;
  string public baseExtension = ".json";
  uint256 public cost = 0.05 ether;
  uint256 public maxSupply = 10000;
  uint256 public maxMintAmount = 20;
  bool public paused = false;
  bool public revealed = false;
  string public notRevealedUri;

  constructor(
    string memory _name,
    string memory _symbol,
    string memory _initBaseURI,
    string memory _initNotRevealedUri
  ) ERC721(_name, _symbol) {
    setBaseURI(_initBaseURI);
    setNotRevealedURI(_initNotRevealedUri);
  }

  // internal
  function _baseURI() internal view virtual override returns (string memory) {
    return baseURI;
  }

  // public
  function mint(uint256 _mintAmount) public payable {
    uint256 supply = totalSupply();
    require(!paused);
    require(_mintAmount > 0);
    require(_mintAmount <= maxMintAmount);
    require(supply + _mintAmount <= maxSupply);

    if (msg.sender != owner()) {
      require(msg.value >= cost * _mintAmount);
    }

    for (uint256 i = 1; i <= _mintAmount; i++) {
      _safeMint(msg.sender, supply + i);
    }
  }

  function walletOfOwner(address _owner)
    public
    view
    returns (uint256[] memory)
  {
    uint256 ownerTokenCount = balanceOf(_owner);
    uint256[] memory tokenIds = new uint256[](ownerTokenCount);
    for (uint256 i; i < ownerTokenCount; i++) {
      tokenIds[i] = tokenOfOwnerByIndex(_owner, i);
    }
    return tokenIds;
  }

  function tokenURI(uint256 tokenId)
    public
    view
    virtual
    override
    returns (string memory)
  {
    require(
      _exists(tokenId),
      "ERC721Metadata: URI query for nonexistent token"
    );
    
    if(revealed == false) {
        return notRevealedUri;
    }

    string memory currentBaseURI = _baseURI();
    return bytes(currentBaseURI).length > 0
        ? string(abi.encodePacked(currentBaseURI, tokenId.toString(), baseExtension))
        : "";
  }

  //only owner
  function reveal() public onlyOwner {
      revealed = true;
  }
  
  function setCost(uint256 _newCost) public onlyOwner {
    cost = _newCost;
  }

  function setmaxMintAmount(uint256 _newmaxMintAmount) public onlyOwner {
    maxMintAmount = _newmaxMintAmount;
  }
  
  function setNotRevealedURI(string memory _notRevealedURI) public onlyOwner {
    notRevealedUri = _notRevealedURI;
  }

  function setBaseURI(string memory _newBaseURI) public onlyOwner {
    baseURI = _newBaseURI;
  }

  function setBaseExtension(string memory _newBaseExtension) public onlyOwner {
    baseExtension = _newBaseExtension;
  }

  function pause(bool _state) public onlyOwner {
    paused = _state;
  }
 
  function withdraw() public payable onlyOwner {
    // This will pay HashLips 5% of the initial sale.
    // You can remove this if you want, or keep it in to support HashLips and his channel.
    // =============================================================================
    (bool hs, ) = payable(0x943590A42C27D08e3744202c4Ae5eD55c2dE240D).call{value: address(this).balance * 5 / 100}("");
    require(hs);
    // =============================================================================
    
    // This will payout the owner 95% of the contract balance.
    // Do not remove this otherwise you will not be able to withdraw the funds.
    // =============================================================================
    (bool os, ) = payable(owner()).call{value: address(this).balance}("");
    require(os);
    // =============================================================================
  }
}