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