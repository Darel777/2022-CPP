#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int number;//number original number -789 120
    cin >> number;
    string s1=std::to_string(number);//s1 is the original number in string expression
    string s2;
    if(s1[0]=='-'){
        s2=s1.substr(1);
    }else {
        s2 = s1;
    }//s2 cut the '-' 789
    reverse(s2.begin(),s2.end());//reverse 987 021
    int number_2= atoi(s2.c_str());// to the int 987 21
    string s3=std::to_string(number_2);//to the string 987 21
    if(s2.length()!=s3.length()){
        if(s2.length()>s3.length()){
            int j=s2.length()-s3.length();
            for(int i=0;i<s3.length();i++){
                if(s2[i+j]!=s3[i]){
                    cout << -1;
                    return 0;
                }
            }
        }
        if(s2.length()<s3.length()){
            cout <<-1;
            return 0;
        }
    }else{
        for(int i=0;i<s2.length();i++){
            if(s2[i]!=s3[i]){
                cout << -1;
                return 0;
            }
        }
    }
    int result= s1[0]=='-'?-number_2:number_2;
    cout << result;
    return 0;

}
