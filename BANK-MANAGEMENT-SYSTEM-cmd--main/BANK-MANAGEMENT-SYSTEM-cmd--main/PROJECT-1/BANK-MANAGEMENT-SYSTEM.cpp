#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
using namespace std;
//START OF DATA STRUCTURE
string employe_id[100];
string password[100];
string customer_name[100];
string customer_phone_number[100];
string customer_address[100];
string customer_cnic[100];
string customer_nationality[100];
string employe_name[100];
string employe_rank[100];
int employe_salary[100];
int account_number[100];
int account_n[100];
int counter = 0;
int counter1 = 0;
int pin[100];
int count0 = 0;
int employe_counter = 0;
int atm_request_account_number[100];
string atm_request_cnic[100];
string atm_request_name[100];
string atm_request_message[100];
string active_sms[100];
string online_banking[100];
int customer_money[100];
int p = 3422;
int a_no = 227771;
int count = 0;
int idx0;
string transaction_type[100];
int transaction_account_no[100];
int transaction_ammount[100];
int transaction_tr_account[100];
int deactivation_account[100];
string reasons[100];
string complains[100];
int complain_account[100];
int counter_complain = 0;
int employe_experience[100];
//END OF DATA STRUCTURE
//START OF FUNCTIONS
void intro_menu();
int  main_menu();
void admin_security1();
void employe_id_checker(string employe_id_temp, string password_temp);
void admin_main_menu();
void add_employe();
int  admin_option_check(int option);
void add_customer();
void change_details(int count);
void display_customer_info(int count);
void account_number_pin_display();
void view_customer_info();
void change_customer_details();
void change_pin();
int  customer_idx();
void customer_money_f();
void atm_request_f();
void withdraw_cash();
void view_atm_request();
void customer_security1();
int  check_customer_option(int option);
void customer_main_menu(int x);
void account_details();
void check_balance();
void active_sms_banking();
void fund_transfer();
void active_online_banking();
void bill_payment();
void transaction_details();
void deactivation_account_f();
int  manager_option_check(int option);
void manager_menu();
void deletion_of_account();
void send_complain();
void view_complains();
void add_employe_to_string(string name, string rank,int experience, int salary, string employe_id_temp, string password_temp);
void add_customer_to_string(string customer_name_temp,string customer_phone_number_temp,string customer_address_temp,string customer_cnic_temp,string customer_nationality_temp);
void view_all_employe();
void employe_deletion();
void  change_employe_details();
void test_data();
void sort();
//END OF FUNCTIONS
//FILE SYSTEM FUNCTIONS
void save_data_employe();
string get_field(string record,int coma_position);
void load_data();
void save_customer_data();
void save_customer_transaction();
void complain_atm();
void atm_request();
//END OF FILW SYSTEM FUNCTIONS
int main()
{
  load_data();
  //test_data();
  intro_menu();
  while (true)
  {
    int option1 = main_menu();
    if (option1 == 1)
    {
      admin_security1();
    }
    else if (option1 == 2)
    {
      customer_security1();
    }
    else if (option1 == 3)
    {
      manager_menu();
    }

    else if (option1 == 4)
    {
      break;
    }
  }
}
void intro_menu()
{
  system("CLS");
  cout<<"**************************************************************************"<<endl;
  cout<<"*                            BANK MANAGEMENT SYSTEM                      *"<<endl;
  cout<<"***************************************************************************"<<endl;
  cout<<"PRESS ANY KEY TO CONTINUE........................................";
  getch();
}
void admin_security1()
{
  string employe_id_temp;
  string password_temp;
  system("CLS");
  cout << "ENTER YOUR EMPLOY_ID=" << endl;
  cin >> employe_id_temp;
  cout << "ENTER YOUR PASSWORD=" << endl;
  cin >> password_temp;
  employe_id_checker(employe_id_temp, password_temp);
}

void employe_id_checker(string employe_id_temp, string password_temp)
{
  bool condition = false;
  for (int x = 0; x <= employe_counter; x++)
  {
    if ((employe_id_temp == employe_id[x]) && (password_temp == password[x]))
    {
      admin_main_menu();
      condition = true;
    }
  }

  if (condition == false)
  {
    cout << "INVALID USER" << endl;
    cout << "PRESS ANY KEY TO CONTINUE...........";
    getch();
  }
}

int main_menu()
{
  system("CLS");
  int option;
  cout<<"**************************************************************************"<<endl;
  cout<<"*                            BANK MANAGEMENT SYSTEM                      *"<<endl;
  cout<<"***************************************************************************"<<endl;
  cout << "SELECT YOUR CATEGORY=" << endl;
  cout << "1.EMPLOYE" << endl;
  cout << "2.CUSTOMER" << endl;
  cout << "3.MANAGER" << endl;
  cout << "4.LOGOUT" << endl;
  cout << "ENTER YOUR OPTION=";
  cin >> option;
  return option;
}

void admin_main_menu()
{

  int u = -1;
  while (u != 0)
  {
    system("CLS");
    cout << "MAIN MENU >> EMPLOYE >>" << endl;
    cout << "1.OPEN CUSTOMER BANK ACCOUNT" << endl;
    cout << "2.TO SEE CUSTOMER INFORMATION" << endl;
    cout << "3.TO CHANGE CUSTOMER PIN" << endl;
    cout << "4.ATM REQUEST" << endl;
    cout << "5.TO DEPOSIT CUSTOMER CASH" << endl;
    cout << "6.TO CHANGE CUSTOMERS DETAILS" << endl;
    cout << "7.TO WITHDRAW CASH" << endl;
    cout << "8.TO VIEW CUSTOMER REQUEST" << endl;
    cout << "9.LOGOUT" << endl;
    cout << "ENTER YOUR OPTION...............=";
    int option;
    cin >> option;
    u = admin_option_check(option);
  }
}
int admin_option_check(int option)
{
  if (option == 1)
  {
    
    add_customer();
  }
  if (option == 2)
  {
    view_customer_info();
  }
  if (option == 3)
  {
    change_pin();
  }
  if (option == 4)
  {
    atm_request_f();
  }
  if (option == 5)
  {
    customer_money_f();
  }
  if (option == 6)
  {
    change_customer_details();
  }
  if (option == 7)
  {
    withdraw_cash();
  }
  if (option == 8)
  {
    view_atm_request();
  }
  if (option == 9)
  {
    return 0;
  }

  return -1;
}
void add_customer()
{ cout<<"MAIN MENU<<OPEN CUSTOMER BANK ACCOUNT"<<endl;
  cout<<endl;
  string customer_name_temp;
  string customer_phone_number_temp;
  string customer_address_temp;
  string customer_cnic_temp;
  string customer_nationality_temp; 
  system("CLS");
  cout << "ENTER CUSTOMER NAME=";
  cin >> customer_name_temp;
  cout << endl;
  cout << "ENTER CUSTOMER PHONE NUMBER=";
  cin >> customer_phone_number_temp;
  cout << endl;
  cout << "ENTER CUSTOMER ADRESS=";
  cin >> customer_address_temp;
  cout << endl;
  cout << "ENTER CNIC OF THE CUSTOMER=";
  cin >> customer_cnic_temp;
  cout << endl;
  cout << "ENTER CUSTOMER NATIONALITY=";
  cin >> customer_nationality_temp;
  
  add_customer_to_string(customer_name_temp,customer_phone_number_temp,customer_address_temp,customer_cnic_temp,customer_nationality_temp);
  system("CLS");
  cout << "BANK ACCOUNT HAS BEEN ACTIVATED........." << endl;
  cout << "PRESS ANY KEY TO SEE DETAILS.............";
  getch();
  



}

void add_customer_to_string(string customer_name_temp,string customer_phone_number_temp,string customer_address_temp,string customer_cnic_temp,string customer_nationality_temp)
{

  customer_name[counter]=customer_name_temp;
  customer_phone_number[counter]=customer_phone_number_temp;
  customer_address[counter]=customer_address_temp;
  customer_cnic[counter]= customer_cnic_temp;
  customer_nationality[counter]=customer_nationality_temp;
  display_customer_info(counter);
  
 

  
  
  
  account_number[counter] = a_no;
  pin[counter] = p;
  save_customer_data();     
      
      
  account_number_pin_display();
        
  getch();
       
      
        p = p + 1;
        a_no = a_no + 1 ;
        counter++;
      
   
}
int customer_idx()
{

  string cnic1;
  int account, idx = -1;
  bool condition = false;
  system("CLS");
  cout << "ENTER CNIC OF THE CUSTOMER=";
  cin >> cnic1;
  cout << endl;
  cout << "ENTER ACCOUNT NUMBER OF THE CUSTOMER=";
  cin >> account;
  cout << endl;
  for (int x = 0; x <= counter; x++)
  {
    if ((account_number[x] == account) && (cnic1 == customer_cnic[x]))
    {

      idx = x;
      idx0 = idx;
      condition = true;
      return idx;
    }
  }
  if (condition == false)
  {
    system("CLS");
    cout << "INVALID USER" << endl;
    cout << "PRESS ANY KEY TO CONTINUE...........";
    getch();
  }
  return idx;
}
void change_details(int count)

{

  int q = -1;
  while (q != 0)
  {
    system("CLS");
    cout<<"MAIN MENU<<CHANGE DETAILS"<<endl;
    cout<<endl;
    int option;
    cout << "1.TO CHANGE NAME" << endl;
    cout << "2.TO CHANGE PHONE NUMBER" << endl;
    cout << "3.TO CHANGE ADRESS" << endl;
    cout << "4.TO CHANGE CNIC" << endl;
    cout << "5.TO CHANGE NATIONALITY" << endl;
    cout << "ENTER ANY OPTION..........";
    cout << "";
    cin >> option;
    if (option == 1)
    {
      system("CLS");
      cout << "ENTER NAME=";
      cin >> customer_name[count];
      save_customer_data();
    }

    if (option == 2)
    {
      system("CLS");
      cout << "ENTER CUSTOMER PHONE NUMBER=";
      cin >> customer_phone_number[count];
      save_customer_data();
    }

    if (option == 3)
    {
      system("CLS");
      cout << "ENTER ADDRESS OF THE CUSTOMER=";
      cin >> customer_address[count];
       save_customer_data();
    }

    if (option == 4)
    {
      system("CLS");
      cout << "ENTER CNIC OF THE CUSTOMER=";
      cin >> customer_cnic[count];
    }

    if (option == 5)
    {
      system("CLS");
      cout << "ENTER NATIONALITY OF THE CUSTOMER=";
      cin >> customer_nationality[count];
      save_customer_data();   
    }
    cout << "RECORD HAS BEEN UPDATED....." << endl;
    cout << "PRESS ANY KEY TO SEE DETAILS OF THE CUSTOMER...." << endl;
    getch();
    display_customer_info(count);
    q = 0;
  }
}
void account_number_pin_display()
{

  system("CLS");
  cout << "ACCOUNT NUMBER OF MRS / MS " << customer_name[counter] << "IS =" << account_number[counter];
  cout << endl;
  cout << "PIN OF THIS ACCOUNT IS = " << pin[counter];
  cout << endl;
  cout << "PRESS ANY KEY TO CONTINUE...............";
  getch();
}
void display_customer_info(int count)

{
  system("CLS");
  cout << endl;
  system("CLS");
  cout << " GENERAL DETAIL OF THE CUSTOMER " << endl;
  cout << "NAME"
       << "\t" << customer_name[count] << endl;
  cout << "PHONE NUMBER"
       << "\t" << customer_phone_number[count] << endl;
  cout << "ADDRESS"
       << "\t" << customer_address[count] << endl;
  
  cout << "CNIC"
       << "\t" << customer_cnic[count] << endl;
  
  cout << "NATIONALITY"
       << "\t" << customer_nationality[count] << endl;
  
  cout << "PRESS ANY KEY TO CONTINUE.........."<<endl;
  getch();
}
void view_customer_info()
{
  int x = customer_idx();
  if (x > -1)
  {
    system("CLS");
    cout<<"MAIN MENU<<VIEW CUSTOMERS DETAILS"<<endl;
    cout<<endl;
    cout << "THE DETAILS OF THE ACCOUNT NUMBER" << account_number[x] << "IS THE FOLLOWING...." << endl;
    cout << "NAME"
         << "\t" << customer_name[x] << endl;
    cout << "PHONE NUMBER"
         << "\t" << customer_phone_number[x] << endl;
    cout << "ADDRESS"
         << "\t" << customer_address[x] << endl;
    ;
    cout << "CNIC"
         << "\t" << customer_cnic[x] << endl;
    ;
    cout << "NATIONALITY"
         << "\t" << customer_nationality[x] << endl;
    cout << "PRESS ANY KEY TO CONTINUE.............." << endl;
    getch();
  }
  if (x == -1)
  {
  }
}
void change_customer_details()
{
  int x = customer_idx();
  if (x > -1)
  {
    change_details(x);
  }
  if (x == -1)
  {
  }
}
void change_pin()
{
  string cnic1;
  int account;
  bool condition = false;
  system("CLS");
  int x = customer_idx();
  if (x > -1)
  {
    cout << "ENTER NEW PIN=";
    cin >> pin[x];
    system("CLS");
    cout << "PIN HAS BEEN UPDATED " << endl;
    cout << "NEW PIN OF THE ACCOUNT NUMBER " << account_number[x] << " IS " << pin[x];
    cout << endl;
    cout << "PRESS ANY KEY TO CONTINUE...";
    getch();
    condition = true;
    save_customer_data();
  }
  if (x == -1)
  {
  }
  save_customer_data();
}
void atm_request_f()
{
  int x = customer_idx();
  if (x > -1)
  {
    atm_request_account_number[count] = account_number[x];
    atm_request_cnic[count] = customer_cnic[x];
    atm_request_name[count] = customer_name[x];
    cout << "ENTER YOUR REQUEST=";
    cin >> atm_request_message[count];
    cout << endl;
    cout << "YOUR REQUEST HAS BEEN TRANSFERED.........." << endl;
    cout << "PRESS ANY KEY TO CONTINUE........";
    count++;
    atm_request();
    getch();
  }
  else if (x == -1)
  {
  }
}
void customer_money_f()
{
  int x = customer_idx();
  if (x > -1)
  {
    int money0 = 0;
    money0 = customer_money[x];
    cout << "ENTER MONEY TO BE DEPOSITED IN MR/MS " << customer_name[x] << " ACCOUNT NUMBER=" << account_number[x] << endl;
    cin >> money0;
    system("CLS");
    cout << " AMMOUNT OF " << money0 << " RS HAS BEEN DEPOSITED" << endl;
    customer_money[x] = customer_money[x] + money0;
    save_customer_data();

    cout << "TOTAL BALANCE IS=" << customer_money[x] << endl;
    cout << "PRESS ANY KEYY TO CONTINUE..............." << endl;
    getch();
    
  }
  else if (x == -1)
  {
  }
}
void withdraw_cash()
{
  int money;
  int x = customer_idx();
  if (x > -1)
  {
    cout << "ENTER AMMOUNT TO BE WITH DRAW=";
    cin >> money;
    if (money > customer_money[x])
    {
      cout << "ACCOUNT BALANCED IS" << customer_money[x] << endl;
      cout << "BALANCED IS LOW" << endl;
      cout << "AMMOUNT CANNOT BE WITH DRAWED=" << endl;
      cout << "PRESS ANY KEY TO CONTINUE" << endl;
      getch();
    }
    else
    {
      int option;
      cout << "ENTER 1 TO CONFIRM THE TRANSACTION " << endl;
      cout << "ENTER 2 TO CLOSE THE TRANSACTION " << endl;
      cin >> option;
      if (option == 1)
      {
        customer_money[x] = customer_money[x] - money;
        cout << "TRANSACTION HAS BEEN DONED" << endl;
        cout << "NEW ACCOUNT BALLANCED IS=" << customer_money[x] << endl;
        cout << "PRESS ANY KEY TO CONTINUE..............";
        transaction_account_no[counter1] = account_number[x];
        transaction_type[counter1] = "WITH_DRAW";
        transaction_ammount[counter1] = money;
        counter1 = counter1 + 1;
        save_customer_transaction();
        save_customer_data();

        getch();
      }
    }
    if (x == -1)
    {
    }
  }
}
void view_atm_request()
{
  system("CLS");
  cout << "ATM REQUEST OF THE CUSTOMERS" << endl;
  for (int x = 0; x < count; x++)
  {

    if(atm_request_name[x]!="")
    {
    cout << "NAME=" << atm_request_name[x] << endl;
    cout << "ACCOUNT NUMBER=" << atm_request_account_number[x] << endl;
    cout << "CNIC=" << atm_request_cnic[x] << endl;
    cout << "MESSAGE=" << atm_request_message[x] << endl;
    cout << endl;
    cout << endl;
     
     }
    cout << "PRESS ANY KEY TO CONTINUE............";
    getch();
  }
}
void customer_security1()
{
  system("CLS");
  int account_no, pinn;
  bool condition = false;
  cout << "ENTER YOUR ACCOUNT NUMBER=";
  cin >> account_no;
  cout << "ENTER YOUR PASSWORD=";
  cin >> pinn;
  for (int x = 0; x < counter; x++)
  {
    if ((account_no == account_number[x]) && (pinn == pin[x]))
    {
      idx0 = x;
      condition = true;
      if (deactivation_account[idx0] == 0)
      {
        customer_main_menu(idx0);
      }

      else if (deactivation_account[idx0] == 1)
      {
        system("CLS");
        cout << "YOUR ACCOUNT IS DEACTIVATED BY THE MANAGER DUE TO THE FOLLOWING REASON..." << endl;
        cout << reasons[idx0];
        getch();
      }
    }
  }

  if (condition == false)
  {
    cout << "INVALID USER";
    getch();
  }
}
void customer_main_menu(int x)
{

  system("CLS");
  cout << "WELCOME DEAR CUSTOMER................" << endl;
  cout << "PRESS ANY KEY TO CONTINUE.............";
  getch();

  int q = -1;
  while (q != 0)
  {
    system("CLS");
    cout << "MAIN MENU>>CUSTOMER" << endl;  
    cout << "1.ACCOUNT DETAILS" << endl;
    cout << "2.CHECK BALANCE" << endl;
    cout << "3.ACTIVE SMS ALERT" << endl;
    cout << "4.FUND TRANSFER" << endl;
    cout << "5.ACTIVE ONLINE BANKING" << endl;
    cout << "6.BILL PAYMENT" << endl;
    cout << "7.TRANSACTION DETAILS" << endl;
    cout << "8.TO SEND COMPLAIN" << endl;
    cout << "9.LOGOUT" << endl;
    cout << "ENTER ANY OPTION=";
    int option;
    cin >> option;
    q = check_customer_option(option);
  }
}
int  check_customer_option(int option)
{

  if (option == 1)
  {
    account_details();
  }
  if (option == 2)
  {
    check_balance();
  }
  if (option == 3)
  {
    active_sms_banking();
  }
  if (option == 4)
  {
    fund_transfer();
  }
  if (option == 5)
  {
    active_online_banking();
  }
  if (option == 6)
  {
    bill_payment();
  }
  if (option == 7)
  {
    transaction_details();
  }
  if (option == 8)
  {
    send_complain();
  }
  if (option == 9)
  {
    return 0;
  }
  return -1;
}
void account_details()
{
  system("CLS");
  cout << endl;
  system("CLS");

  cout << "ACCOUNT NUMBER=" << account_number[idx0] << endl;
  cout << "PIN IS =" << pin[idx0] << endl;
  cout << " GENERAL DETAIL OF THE CUSTOMER " << endl;
  cout << "NAME"
       << "\t" << customer_name[idx0] << endl;
  cout << "PHONE NUMBER"
       << "\t" << customer_phone_number[idx0] << endl;
  cout << "ADDRESS"
       << "\t" << customer_address[idx0] << endl;
  ;
  cout << "CNIC"
       << "\t" << customer_cnic[idx0] << endl;
  ;
  cout << "NATIONALITY"
       << "\t" << customer_nationality[idx0] << endl;
  if (active_sms[idx0] == "YES")
  {
    cout << "SMS ALERT SERVICE IS ACTIVE" << endl;
  }
  else if (active_sms[idx0] != "YES")
  {

    cout << "SMS ALERT SERVICE IS NOT ACTIVE" << endl;
  }

  if (online_banking[idx0] == "YES")
  {
    cout << "ONLINE BANKING HAS BEEN ACTIVATED" << endl;
  }
  else if (online_banking[idx0] != "YES")
  {

    cout << "ONLINE BANKING HAS NOT BEEN ACTIVATED" << endl;
  }

  getch();
}
void check_balance()
{
  system("CLS");
  cout << "YOUR ACCOUNT BALANCE IS=" << customer_money[idx0] << endl;
  cout << "PRESS ANY KEY TO CONTINUE............";
  getch();
}

void active_sms_banking()
{
  
  for(int x=0;x<=10;x++)
  {active_sms[x]="NO";}
  
  cout << "ENTER YES TO ACTIVATE SMS ALERT AND NO TO DEACTIVATE SMS ALERT SERVICE=";
  cin >> active_sms[idx0];
  if (active_sms[idx0] == "YES")
  {
    system("CLS");
    save_customer_data();
    cout << "SMS ALERT SERVICE HAS BEEN ACTIVATED" << endl;
    cout << "PRESS ANY KEY TO CONTINUE.........";
    getch();
  }
  else if (active_sms[idx0] == "NO")
  {
    system("CLS");
    save_customer_data();
    cout << "SMS ALERT SERVICE HAS BEEN DEACTIVATED" << endl;
    cout << "PRESS ANY KEY TO CONTINUE.........";
    getch();
  }
  else if (active_sms[idx0] != "YES" && active_sms[idx0] != "NO")
  {
    system("CLS");
    cout << "INVALID COMMAND" << endl;
    cout << "PRESS ANY KEY TO CONTINUE.........";
    getch();
  }
  
}
void fund_transfer()
{
  int ammount;
  string cnic1;
  int account;
  bool condition = false;
  int y;
  system("CLS");
  cout << "ENTER CNIC OF THE CUSTOMER=";
  cin >> cnic1;
  cout << endl;
  cout << "ENTER ACCOUNT NUMBER OF THE CUSTOMER=";
  cin >> account;
  cout << endl;
  if (account != account_number[idx0])
  {
    for (int x = 0; x <= counter; x++)
    {
      if ((account_number[x] == account) && (cnic1 == customer_cnic[x]))
      {
        y = x;
        condition = true;
      }
    }
    if (condition == true)
    {
      cout << "ENTER AMMOUNT TO BE DEPOSITED=";
      cin >> ammount;
      if (customer_money[idx0] >= ammount)
      {
        transaction_account_no[counter1] = account_number[idx0];
        transaction_tr_account[counter1] = account;
        transaction_type[counter1] = "FUND TRANSFER";
        transaction_ammount[counter1] = ammount;
        counter1++;
        customer_money[y] = customer_money[y] + ammount;
        customer_money[idx0] = customer_money[idx0] - ammount;
        cout << "AMMOUNT HAS BEEN TRANSFERED SUCESSFULLY......" << endl;
        cout << "PRESS ANY KEY TO CONTINUE......";
        save_customer_transaction();
        save_customer_data();;
        getch();
      }
      else
      {
        cout << "ACCOUNT BALANCED IS=" << customer_money[idx0] << endl;
        cout << "AMMOUNT BALANCED IS LOW......" << endl;
        cout << "PRESS ANY KEY TO CONTINUE......";
        getch();
      }
    }
    if (condition == false)
    {
      cout << "INVALID ACCOUNT" << endl;
      cout << "PRESS ANY KEY TO CONTINUE...............";
      getch();
    }
  }
  else if (account == account_number[idx0])
  {
    cout << "ACCOUNT NUMBER IS LOGED INN" << endl;
    cout << "PRESS ANY KEY TO CONTINU...............";
    getch();
  }
}
void active_online_banking()
{
  for (int x=0;x<=10;x++)
  {
    online_banking[x]="NO";
  }
  
  
  
  cout << "ENTER YES TO ACTIVATE ONLINE BANKING AND NO TO DEACTIVATE ONLINE BANKING=";
  cin >> online_banking[idx0];
  ;
  if (online_banking[idx0] == "YES")
  {
    system("CLS");
    cout << "SMS ALERT SERVICE HAS BEEN ACTIVATED" << endl;
    cout << "PRESS ANY KEY TO CONTINUE.........";
    getch();
    save_customer_data();
  }
  else if (online_banking[idx0] == "NO")
  {
    system("CLS");
    cout << "SMS ALERT SERVICE HAS BEEN DEACTIVATED" << endl;
    cout << "PRESS ANY KEY TO CONTINUE.........";
    getch();
    save_customer_data();
  }
  else if (online_banking[idx0] != "YES" && online_banking[idx0] != "NO")
  {
    system("CLS");
    cout << "INVALID COMMAND" << endl;
    cout << "PRESS ANY KEY TO CONTINUE.........";
    getch();
  }
}
void bill_payment()
{
  string bill_type;
  string refrence_number;
  int ammount_;
  system("CLS");
  cout << "1.ELECTRIC BILL" << endl;
  cout << "2.WATER BILL" << endl;
  cout << "3,PHONE PAYMENT" << endl;
  cout << "ENTER BILL TYPE=";
  cin >> bill_type;
  cout << endl;
  if (bill_type == "ELECTRIC" || bill_type == "WATER" || bill_type == "PHONE")
  {

    cout << "ENTER REFRENCE NUMBER=";
    cin >> refrence_number;
    cout << endl;
    cout << "ENTER  AMMOUNT TO BE PAYED=";
    cin >> ammount_;
    cout << endl;
    if (ammount_ <= customer_money[idx0])
    {
      transaction_account_no[counter1] = account_number[idx0];
      transaction_type[counter1] = bill_type;
      transaction_ammount[counter1] = ammount_;
      counter1 = counter1 + 1;
      customer_money[idx0] = customer_money[idx0] - ammount_;
      cout << "TRANSACTION HAS BEEN DONED" << endl;
      cout << "NEW ACCOUNT BALANCED IS" << customer_money[idx0];
      cout << "PRESS ANY KEY TO CONTINUE..............";
      save_customer_transaction();
      save_customer_data();
      getch();
    }
    else
    {
      cout << "ACCOUNT BALANCED IS LOW" << endl;
      cout << "ACCOUNT BALANCED IS=" << customer_money[idx0] << endl;
      cout << "PRESS ANY KEY TO CONTINUE..............";
      getch();
    }
  }
  else
  {

    cout << "INVALID BILL TYPE" << endl;
    cout << "PRESS ANY KEY TO CONTINUE" << endl;
    getch();
  }
}
void transaction_details()
{
  system("CLS");
  cout << "BILL PAYMENT" << endl;
  for (int x = 0; x <= counter1; x++)
  {

    if (transaction_account_no[x] == account_number[idx0] && (transaction_type[x] == "ELECTRIC" || transaction_type[x] == "WATER" || transaction_type[x] == "PHONE"))
    {
      cout << transaction_account_no[x] << "\t" << transaction_type[x] << "\t" << transaction_ammount[x] << "\t" << transaction_tr_account[x] << endl;
    }
  }

  cout << endl;
  cout << endl;
  cout << "FUND TRANSFER" << endl;
  for (int x = 0; x <= counter1; x++)
  {

    if (transaction_account_no[x] == account_number[idx0] && transaction_type[x] == "FUND TRANSFER")
    {
      cout << transaction_account_no[x] << "\t" << transaction_type[x] << "\t" << transaction_ammount[x] << "\t" << transaction_tr_account[x] << endl;
    }
  }
  cout << endl;
  cout << endl;
  cout << "WITH DRAW BALANCE" << endl;
  for (int x = 0; x <= counter1; x++)
  {

    if (transaction_account_no[x] == account_number[idx0] && transaction_type[x] == "WITH_DRAW")
    {
      cout << transaction_account_no[x] << "\t" << transaction_type[x] << "\t" << transaction_ammount[x] << "\t" << transaction_tr_account[x] << endl;
    }
  }
  getch();
}
void send_complain()
{
  system("CLS");
  cout << "ENTER YOUR COMPLAINN=";
  cin >> complains[counter_complain];
  complain_account[counter_complain] = account_number[idx0];
  complain_atm();
  counter_complain = counter_complain + 1;
  cout << "YOUR COMPLAIN HAS BEEN SEND TO THE MANAGER...." << endl;
  cout << "PRESS ANY KAY TO CONTINUE.......";
  
  getch();
}
void manager_menu()
{

  string username;
  int password;
  cout << "ENTER YOUR USER NAME=";
  cin >> username;
  cout << endl;
  cout << "ENTER YOUR PASSWORD=";
  cin >> password;
  cout << endl;
  if (username == "MANAGER" && password == 1114)
  {
    int q = -1;

    system("CLS");
    cout << "WELCOME DEAR MANAGER......." << endl;
    cout << "PRESS ANY KAY TO CONTINUE...........";
    getch();
    while (q != 0)
    {
      system("CLS");
      cout<<"MAIN MENU>>MANAGER>>"<<endl;
      cout << "1.DEACVTIVATE OR ACTIVATE CUSTOMER ACCOUNT" << endl;
      cout << "2.DELETION OF CUSTOMER ACCOUNT" << endl;
      cout << "3.VIEW CUSTOMERS COMPLAIN" << endl;
      cout << "4.VIEW ATM REQUEST" << endl;
      cout << "5.ADD EMPLOYE" << endl;
      cout << "6.VIEW ALL EMPLOYE" << endl;
      cout << "7.DELETE EMPLOYE" << endl;
      cout << "8.VIEW EMPLOYE WITH LARGEST EXPERIENCES IN HIS/HER FIELD" << endl;
      cout << "9.CHANGE EMPLOYE DETAILS" << endl;
      cout << "10.LOGOUT" << endl;
      cout << endl;
      int option;
      cout << "ENTER ANY OPTION= ";
      cin >> option;

      q = manager_option_check(option);
    }
  }
  else
  {
    cout << "INVALID USER..";
    getch();
  }
}

int manager_option_check(int option)
{
  if (option == 1)
  {
    deactivation_account_f();
  }
  if (option == 2)
  {
    deletion_of_account();
  }
  if (option == 3)
  {
    view_complains();
  }
  if (option == 4)
  {
    view_atm_request();
  }
  if (option == 5)
  {
    add_employe();
  }
  if (option == 6)
  {
    view_all_employe();
  }
  if (option == 7)
  {
    employe_deletion();  
  }
  if (option == 8)
  {
    sort();
  }
   if (option == 9)
  {
    change_employe_details();
  }
  
   if (option == 10)
  {
    return 0;
  }
  
  
  return -1;
}
void deactivation_account_f()
{
  int x = customer_idx();
  if (x > -1)
  {
    string answer;
    cout << "ENTER YES TO DEACTIVATE THIS ACCOUNT " << account_number[x] << "AND NO TO ACTIVATE THIS ACCOUNT" << endl;
    cin >> answer;
    if (answer == "YES")
    {
      deactivation_account[x] = 1;
      cout << "ENTER REASON TO DEACTIVATE THIS ACCOUNT......";
      cin >> reasons[idx0];
    }
    else if (answer == "NO")
    {
      deactivation_account[x] = 0;
    }
    else
    {
      cout << "INVALID CAMMAND";
      cout << endl;
    }
  }
  else if (x == -1)
  {
  }
}
void deletion_of_account()
{

  int x = customer_idx();
  int temp_idx1 = x;
  int temp_idx2 = x;
  if (x > -1)
  {
    while (temp_idx1 < counter)
    {
      temp_idx2 = temp_idx1 + 1;
      customer_cnic[temp_idx1] = customer_cnic[temp_idx2];
      customer_name[temp_idx1] = customer_name[temp_idx2];
      customer_phone_number[temp_idx1] = customer_phone_number[temp_idx2];
      customer_address[temp_idx1] = customer_address[temp_idx2];
      customer_nationality[temp_idx1] = customer_nationality[temp_idx2];
      account_number[temp_idx1] = account_number[temp_idx2];
      account_n[temp_idx1] = account_n[temp_idx2];
      pin[temp_idx1] = pin[temp_idx2];
      transaction_account_no[temp_idx1] = transaction_account_no[temp_idx2];
      customer_money[temp_idx1] = customer_money[temp_idx2];
      deactivation_account[temp_idx1] = deactivation_account[temp_idx2];

      atm_request_account_number[temp_idx1] = atm_request_account_number[temp_idx2];
      atm_request_cnic[temp_idx1] = atm_request_cnic[temp_idx2];
      atm_request_name[temp_idx1] = atm_request_name[temp_idx2];
      atm_request_message[temp_idx1] = atm_request_message[temp_idx2];

      temp_idx1 = temp_idx1 + 1;
    }
  }
  else if (x == -1)
  {
  }
save_customer_data();  

}
void view_complains()
{
  for (int x = 0; x < counter_complain; x++)
  {
    if (complain_account[x] == account_number[x])

    {
      system("CLS");
      cout << complain_account[x] << endl;
      cout << complains[x];
      cout << endl;
    }
  }
  getch();
}
void add_employe()
{
  string employe_id_temp;
  string password_temp;
  string name;
  string rank;
  int experience;
  int salary;
  cout << "ENTER NAME OF THE EMPLOYE=";
  cin >> name;
  cout << endl;
  cout << "ENTER RANK OF THE EMPLOYE=";
  cin >> rank;
  cout << endl;
  cout<<"ENTER YEARS OF HIS/HER EXPERIENCE=";
  cin>> experience;
  cout << endl;
  cout << "ENTER SALARY OF THE EMPLOYE" << endl;
  cin >> salary;
  cout << endl;
  cout << "ENTER ID OF THE EMPLOYE=" << endl;
  cin >> employe_id_temp;
  cout << endl;
  cout << "ENTER PASSWORD OF THE EMPLOYE";
  cin >> password_temp;
  add_employe_to_string(name, rank, experience, salary, employe_id_temp, password_temp);
  system("CLS");
  cout << "EMPLOYE HAS BEEN ADDED SUCESSFULLY";
  getch();
}
void add_employe_to_string(string name, string rank,int experience,int salary, string employe_id_temp, string password_temp)
{
  employe_id[employe_counter] = employe_id_temp;
  password[employe_counter] = password_temp;
  employe_name[employe_counter] = name;
  employe_rank[employe_counter] = rank;
  employe_experience[employe_counter]=experience;
  employe_salary[employe_counter] = salary;
  employe_counter = employe_counter + 1;
  save_data_employe();


}


void view_all_employe()
{
  system("CLS");
  cout << "FOLLOWING EMPLOYS ARE ADDED BY YOU" << endl;
  cout << endl;
  cout << endl;
  for (int x = 0; x < employe_counter; x++)
  {
    if (employe_name[x]!="")
    {
    cout << "EMPLOYE NAME=" << employe_name[x] << endl;
    cout << "EMPLOYE RANK=" << employe_rank[x] << endl;
    cout << "EMPLOYE SALRY=" << employe_salary[x] << endl;
    cout << "EMPLOYE EXPERIENCE=" << employe_experience[x] << endl;
    cout << "EMPLOYE ID=" << employe_id[x] << endl;
    cout << "EMPLOYE PASSWORD=" << password[x] << endl;
    cout << endl;
    cout << endl;
    }
  
  }
  getch();
}
void employe_deletion()
{
  bool condition=false;
  int idx2,idx;
  string employe_id_temp;
  string employe_name_temp;
  cout << "ENTER EMPLOYE ID=";
  cin >> employe_id_temp;
  cout << endl;
  cout << "ENTER NAME OF THE EMPLOYE";
  cin >> employe_name_temp;
  for (int x = 0; x <= employe_counter; x++)
  {
    if (employe_id_temp == employe_id[x] &&  employe_name_temp==employe_name[x])
  
    {
       while(x<=employe_counter)
       {
       idx=x;
       idx2=x+1;
       employe_id[idx]= employe_id[idx2];
       password[idx] =   password[idx2];
       employe_name[idx] =  employe_name[idx2];
       employe_rank[idx] =  employe_rank[idx2]; 
       employe_salary[idx] = employe_salary[idx2];
       employe_experience[idx] = employe_experience[idx2];
       //cout<<employe_name[idx]<<","<<employe_name[idx2]<<endl; 
       //cout<<idx<<","<<idx2;
       save_data_employe();
       idx=idx+1;
       x=x+1;
       }
    
    }
  }

       cout<<"ACCOUNT HAS BEEN DELETED SUCESSFULLY."<<endl;
       cout<<"PRESS ANY KEY TO CONTINUE...................."<<endl;
       getch(); 
}
void sort()
{

int experience[100];
int employe_experience_temp[100];
for (int x=0;x<employe_counter;x++)
{
  employe_experience_temp[x]=employe_experience[x];
}




  for(int idx=0;idx<employe_counter;idx++)

    {

            int largest=-10000;
            int largest_number_idx=0;
        
            for(int y=0;y<employe_counter;y++)    
          {

            if(largest<employe_experience_temp[y])
             {
                largest=employe_experience_temp[y];
                largest_number_idx=y;
             }
          } 
    
         experience[idx]=largest_number_idx;
         employe_experience_temp[largest_number_idx]=-1;
         largest=-10000;         
    }      


 for(int x=0;x<employe_counter;x++)
 {
   
  int y=experience[x];

 if(employe_name[y]!="")
 {
    cout<<"NAME="<<employe_name[y]<<endl;
    cout<<"rank="<<employe_rank[y]<<endl;
    cout<<"SALARY="<<employe_salary[y]<<endl;
    cout<<"EXPERIENCE="<<employe_experience[y]<<endl;
    cout<<"EMPLOYE ID="<<employe_id[y]<<endl;
    cout<<"EMPLOYE PASSWORD="<<password[y]<<endl;
    cout<<endl;
     cout<<endl;
 
 }
 
 }

getch();

}

void  change_employe_details()
{

  string employe_id_temp;
  string employe_name_temp;
  cout << "ENTER EMPLOYE ID=";
  cin >> employe_id_temp;
  cout << endl;
  cout << "ENTER NAME OF THE EMPLOYE";
  cin >> employe_name_temp;
  for (int x = 0; x <= employe_counter; x++)
  {
    if (employe_id_temp == employe_id[x] &&  employe_name_temp==employe_name[x])
  
    {

      cout<<"1.CHANGE NAME"<<endl;
      cout<<"2.CHANGE RANK"<<endl;
      cout<<"3.CHANGE SALARY"<<endl;
      cout<<"4.CHANGE EXPERIENCE"<<endl;
      cout<<"5.CHANGE EMPLOYE ID"<<endl;
      cout<<"6.CHANGE EMPLOYE PASSWORD"<<endl;
      int option1;
      cin>>option1;  
         if(option1==1)
        {  cout<<"ENTER NEW NAME="<<endl;
           cin>>employe_name[x];
          cout<<"PROFILE HAS BEEN UPDATED"<<endl; 
          save_data_employe();                     }
           
         if(option1==2)
        { cout<<"ENTER NEW RANK"<<endl;
          cin>>employe_rank[x];
          cout<<"PROFILE HAS BEEN UPDATED"<<endl; 
          save_data_employe();                     }
          
         if(option1==3)
       {    cout<<"ENTER NEW SALARY"<<endl; 
         cin>>employe_salary[x];
          cout<<"PROFILE HAS BEEN UPDATED"<<endl; 
          save_data_employe();                      }
         
         if(option1==4)
       { cout<<"ENTER NEW EXPERIENCE"<<endl;
         cin>> employe_experience[x];
          cout<<"PROFILE HAS BEEN UPDATED"<<endl; 
          save_data_employe();                      }
         
         if(option1==5)
       {   cout<<"ENTER NEW ID"<<endl; 
           cin>> employe_id[x];
          cout<<"PROFILE HAS BEEN UPDATED"<<endl; 
          save_data_employe();                     }
           
         if(option1==6)
       { cout<<"ENTER NEW PASSWORD"<<endl;  
         cin>> password[x];
        cout<<"PROFILE HAS BEEN UPDATED"<<endl; 
        save_data_employe();                       }
     

    }
  }
}


void save_data_employe()
{
fstream file;
file.open("employe_data.txt",ios::out);
string record;
for(int x=0;x<=employe_counter;x++)
{
if(employe_name[x]!="")
{ 
record=employe_name[x]+","+employe_rank[x]+","+to_string(employe_experience[x])+","+to_string(employe_salary[x])+","+employe_id[x]+","+password[x]+"\n";
file<<record;
}
}
file.close();
}


void load_data()
{
    fstream file_1;
    file_1.open("employe_data.txt",ios::in);
    string record_1;
    while(getline(file_1,record_1))
    {
      
      employe_name[employe_counter]=get_field(record_1,1);
      employe_rank[employe_counter]=get_field(record_1,2);
      employe_experience[employe_counter]=stoi(get_field(record_1,3));
      employe_salary[employe_counter]=stoi(get_field(record_1,4));  
      employe_id[employe_counter]=get_field(record_1,5);
      password[employe_counter]=get_field(record_1,6);
      employe_counter=employe_counter+1; 

    }
    file_1.close();
//record_1=customer_name[x]+","+customer_nationality[x]+","+customer_phone_number[x]+","+customer_address[x]+","+customer_cnic[x]+","+to_string(account_number[x])+","+to_string(pin[x])+","+to_string(customer_money[x])+","+to_string(deactivation_account[x])+"\n";


    fstream file_2;
    file_2.open("customer_data.txt",ios::in);
    string record_2;
    while(getline(file_2,record_2))
    { 
       customer_name[counter]=get_field(record_2,1);  
       customer_nationality[counter]=get_field(record_2,2);   
       customer_phone_number[counter]=get_field(record_2,3);  
       customer_address[counter]=get_field(record_2,4);    
       customer_cnic[counter]=get_field(record_2,5);   
       account_number[counter]=stoi(get_field(record_2,6));  
       pin[counter]=stoi(get_field(record_2,7));  
       customer_money[counter]=stoi(get_field(record_2,8));  
       deactivation_account[counter]=stoi(get_field(record_2,9)); 
       p = p + 1;
       a_no=a_no + 1;
     //  cout<<p;
     //  cout<<a_no;
       
       counter=counter+1;
   }   
 
   file_2.close();

//transaction_account_no[x])+","+transaction_type[x]+","+to_string(transaction_ammount[x])+"\n";


    fstream file_3;
    file_3.open("customer_transaction.txt",ios::in);
    string record_3;
    while(getline(file_3,record_3))
    { 

     transaction_account_no[counter1]=stoi(get_field(record_3,1));
     transaction_type[counter1]=get_field(record_3,2);
     transaction_ammount[counter1]=stoi(get_field(record_3,3)); 
     counter1=counter1+1; 
    }   
 
   file_3.close();
   

    fstream file_4;
    file_4.open("complain_atm.txt",ios::in);
    string record_4;
    while(getline(file_4,record_4))
    { 

     complain_account[counter_complain]=stoi(get_field(record_4,1));
     complains[counter_complain]=get_field(record_4,2);
     counter_complain=counter_complain+1; 
    
    }   
 
   file_4.close();

   fstream file_5;
    file_5.open("atm_request.txt",ios::in);
    string record_5;
    while(getline(file_5,record_5))
    { 
    atm_request_account_number[count]=stoi(get_field(record_5,1));
    atm_request_cnic[count]=get_field(record_5,2);
    atm_request_name[count]=get_field(record_5,3);
    atm_request_message[count]=get_field(record_5,4);  
    count=count+1; 
    }   
  file_5.close();

}


string get_field(string record,int coma_position)
{
string field="";
int coma_found=0;
int idx=0;
while(coma_found<coma_position  && idx<record.length())
{
char c=record[idx];
if(c==',')
{coma_found=coma_found+1;}
else if(coma_found==coma_position-1)
{
  field=field+c;
}
idx=idx+1;
}
return field;
}



void save_customer_data()
{
fstream file;
file.open("customer_data.txt",ios::out);
string record;
for(int x=0;x<=counter;x++)
{
if(customer_name[x]!="")
{ 
system("CLS"); 
record=customer_name[x]+","+customer_nationality[x]+","+customer_phone_number[x]+","+customer_address[x]+","+customer_cnic[x]+","+to_string(account_number[x])+","+to_string(pin[x])+","+to_string(customer_money[x])+","+to_string(deactivation_account[x])+","+active_sms[x]+","+online_banking[x]+"\n";
file<<record;
}
}
file.close();
}

void save_customer_transaction()
{
fstream file;
file.open("customer_transaction.txt",ios::out);
string record;
for(int x=0;x<=counter1;x++)
{ 
if(transaction_type[x]!="")
{
record=to_string(transaction_account_no[x])+","+transaction_type[x]+","+to_string(transaction_ammount[x])+"\n";
file<<record;
}
}
file.close();
}

void complain_atm()
{
fstream file;
file.open("complain_atm.txt",ios::out);
string record;
for(int x=0;x<=counter_complain;x++)
{ 
record=to_string(complain_account[x])+","+complains[x]+"\n";
file<<record;
}
file.close();
}



void atm_request()
{
fstream file;
file.open("atm_request.txt",ios::out);
string record;
for(int x=0;x<=count;x++)
{ 
if(atm_request_message[x]!="")
{  
record=to_string(atm_request_account_number[x])+","+atm_request_cnic[x]+","+atm_request_name[x]+","+atm_request_message[x]+"\n";
file<<record;
}
}
file.close();
}




void test_data()
{

//add_employe_to_string(string name, string rank, int salary, string employe_id_temp, string password_temp);
//add_customer_to_string(string customer_name_temp,string customer_phone_number_temp,string customer_address_temp,string customer_cnic_temp,string customer_nationality_temp);

add_employe_to_string("MUSAWIR","SOFTWARE_DEVELOPER",10,70000,"EM1","IT1");
employe_counter=employe_counter+1;
add_customer_to_string("ALI","03204502556","JOHAR_TOWN","35202","PAKISTANI");
//counter=counter+1;

add_employe_to_string("BILAL","CLERK",4,10000,"EM2","IT2");
employe_counter=employe_counter+1;
add_customer_to_string("HASSAN","0322453334","KARACHI","35102","PAKISTANI");
//counter=counter+1;


add_employe_to_string("AHMED","CASHIER",17,20000,"EM3","IT3");
employe_counter=employe_counter+1;
add_customer_to_string("UMER","03206577556","SAILKOT","35501","PAKISTANI");
//counter=counter+1;


}