#include "bankaccount.h"

Account::Account(){
    BankAmount = 0.0;
}

//Deconstructor empty for now could possibly be used down the road
Account::~Account()
{}

Account::Account(const Account& A)
{
    AccountNumber = A.AccountNumber;
    FirstName = A.FirstName; 
    LastName = A.LastName; 
    BankAmount = A.BankAmount;
    type = A.type;
}
void Account::AccountOptions(){
    char answer;
    
    cout << "+++++++++++++++++++++++++++++++++++++++++\n";
    cout << "+\t" <<"Different Account Opotions" << "\t+\n";
    cout << "+\t" <<"C: Checking Account" << "\t\t+\n";
    cout << "+\t" << "S: Savings Account" << "\t\t+\n";
    cout << "+++++++++++++++++++++++++++++++++++++++++\n";
    cout << "Please choose an Account type from the menu\n";
    cout << ">";
    cin >> answer;
    
    switch(answer){
        case 'C':
        case 'c':
                type = CHECKINGS;
                break;
        case 'S':
        case 's':
                type = SAVINGS;
                break;
        default: 
                cout << "Invaild Option" << endl;
                cout << "Set to Default Type: Checking" << endl;
                type = CHECKINGS;
                break;
    }
}

void Account::Setup(){
    char answer;
    double amount = GetBankAmount(); 

    srand(time(NULL));                  //inital seed for randomization

    AccountNumber = rand() % 1000 + 1;  //Random Account number for each account
    
    AccountOptions();
    
    cout << "Enter first name: ";
    cin >> FirstName;

    cout << "Enter last name: ";
    cin >> LastName; 
}

double Account::Deposit(double amount){
    BankAmount = BankAmount + amount;
    cout << "Amount:$ " << amount << " has been successfully added to your account\n";
    cout << "Thank you" << endl;
    return BankAmount; 
}

double Account::Withdraw(double amount){
    if(amount > BankAmount)
    {
        cout << "Error:$" << amount << " is greater then what is inside bank account\n";
        return 0; 
    }
    BankAmount = BankAmount - amount;
    cout << "Thank you" << " the amount of $" << amount << " has been successfully withdrawn from your account\n";
    return BankAmount;
}

string Account::GetFirstName(){
    return FirstName;
}

string Account::GetLastName(){
    return LastName;
}

int Account::GetAccountNumber(){
   return AccountNumber;
}

double Account::GetBankAmount(){
    return BankAmount; 
}

string Account::GetType(){
    string answer;

    if(type == CHECKINGS)
    {
        answer = "Checkings";
    } 
    else if(type == SAVINGS)
    {
        answer = "Savings";
    }
    return answer;
}
void  Account::SetFirstName(string Fname)
{
    FirstName = Fname;
}
void Account::SetLastName(string Lname)
{
    LastName = Lname;
}
void Account::SetAccountNumber(int ANumber)
{
    AccountNumber = ANumber; 
}
void Account::SetAccountType(string type)
{
    if(type == "Checking")
        type = CHECKINGS;
    else if(type == "Saving")
        type = SAVINGS;

}
void Account::SetAccountAmount(double Aamount)
{
   BankAmount = Aamount;  
}
