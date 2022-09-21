#include <iostream>
#include <string>
using namespace std;

int main() {
    string input="";
    cin >> input;
    int index;
    cin >>index;//index是z形状的行数
    if(index==1){
        cout << input;
        return 0;
    }

    string result="";
    int gap=(index-1)*2;//every loop jump 'gap' numbers
    int final_count=input.length()-1;//final count symbol

    for(int i=0;i<=index-1;i++){//6 lines from 0 to 5
        int k=i;
        if(k<=final_count){
        result=result+(input[k]);}
        while(k<=final_count){
            int a=gap-i*2;//10-0*2
            int b=gap-a;//10-10
            if(a!=0){
                k=k+a;
                if(k<=final_count){
                result=result+(input[k]);}
            }
            if(b!=0){
                k=k+b;
                if(k<=final_count){
                    result=result+(input[k]);}
            }
        }
    }


    cout <<result;

}
