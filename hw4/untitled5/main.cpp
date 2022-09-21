#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class account{
public:
    int type;
    account(int type);
    double Interest_cal();
    double money=0;
};
account::account(int type) {
    this->type=type;
}

double account::Interest_cal() {
    if(type==0){
        return this->money*0.001;
    }else if(type==1){
        if(this->money<=1000){
            return this->money*0.001;
        }else{
            return this->money*0.002-1;
        }
    }else{
        if(this->money<=1000){
            return this->money*0.02;
        }else if(this->money<=2000){
            return this->money*0.05-30;
        }else{
            return this->money*0.1-130;
        }
    }
}
class customer{
public:
    string name;
    vector<int> having_accounts;
    customer(string name);
};
customer::customer(string name) {
    this->name=name;
}
int main() {
    vector<account> accounts;
    vector<customer> customers;
    while(1){
        string instruction;
        cin >>instruction;
        if(instruction=="createAccount"){
            int type;
            cin >> type;
            account account1=account(type);
            accounts.emplace_back(account1);
        }else if(instruction=="createCustomer"){
            string name;
            cin >> name;
            customer customer1=customer(name);
            customers.emplace_back(customer1);
        }else if(instruction=="addToCustomer"){
            int index; string name;
            cin >> index; cin >> name;
            for(int i=0;i<customers.size();i++){
                if(customers[i].name==name){
                    customers[i].having_accounts.emplace_back(index);
                }
            }
        }else if(instruction=="accountDeposit"){
            int index; double amount;
            cin >> index; cin >> amount;
            if(amount>=0){
                accounts[index].money+=amount;
            }else{
                cout << "amount must be greater than zero" << endl;
            }
        }else if(instruction=="accountWithdraw"){
            int index; double amount;
            cin >> index; cin >> amount;
            if(amount>=0&&accounts[index].money-amount>=0){
                accounts[index].money-=amount;
            }else if(amount<0){
                cout << "amount must be greater than zero" << endl;
            }else if(accounts[index].money-amount<0){
                cout << "sumTransactions must be greater than zero" << endl;
            }
        }else if(instruction=="sumTransactions"){
            int index;cin >> index;
            cout << accounts[index].money << endl;
        }else if(instruction=="numberOfAccount"){
            string name; cin >> name;
            for(int i=0;i<customers.size();i++){
                if(customers[i].name==name){
                    cout << customers[i].having_accounts.size() << endl;
                }
            }
        }else if(instruction=="totalInterestEarned"){
            double sum=0;
            string name; cin >> name;
            for(int i=0;i<customers.size();i++){
                if(customers[i].name==name){
                    for(int j=0;j<customers[i].having_accounts.size();j++){
                        sum+=accounts[customers[i].having_accounts[j]].Interest_cal();
                    }
                }
            }
            cout << sum << endl;
        }else if(instruction=="getStatement"){

        }else if(instruction=="banktotalInserstPaid"){
            double sum=0;
            for(int i=0;i<accounts.size();i++){
                sum+=accounts[i].Interest_cal();
            }
            cout << sum << endl;
        }else if(instruction=="customsum"){

        }else{
            break;
        }
    }
}
