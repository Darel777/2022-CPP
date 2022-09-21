#include <iostream>
using namespace std;
int get_number(char* array);

int main() {
    int iterator=0;//location now
    int size=0;//factual number
    int capacity=0;//capacity the maximum numbers now
    int a[100];

    int code_lines=0;
    cin >> code_lines;
    getchar();


    for(int i=0;i<code_lines;i++){

        char got[100];
        cin >> got;

        int number;

        //mode switch
        int mode=0;//mode1 add mode2 remove mode3 get mode4 getSize mode5 getCapacity
        int code_itr=0;
        while(got[code_itr]!='\0'){
            if(got[code_itr]=='d'){
                mode=1;
                break;
            }
            if(got[code_itr]=='r'){
                mode=2;
                break;
            }
            if(got[code_itr]=='S'){
                mode=4;
                break;
            }
            if(got[code_itr]=='C') {
                mode=5;
                break;
            }
            code_itr++;
        }
        if(mode==0){
            mode=3;
        }

        if(mode==1){//add
            if(capacity==0){
                capacity=10;
            }
            if(size==capacity){
                capacity=capacity+capacity/2;
            }
            cin >> number;
            a[size++]= number;
        }
        if(mode==2){//remove
            cin >>number;
            for(iterator=0;iterator<size;iterator++){
                if(a[iterator]== number){
                    for(int j=iterator;j<=size-1;j++){
                        a[j]=a[j+1];
                    }
                    size=size-1;
                    break;
                }
            }
        }
        if(mode==3){//get
            cin >>number;
            if(number>=size){
                cout << -1;

            }else{
                cout << a[number];
            }
        }
        if(mode==4){
            cout << size;

        }
        if(mode==5){
            cout << capacity;

        }

    }

    return 0;
}

int  get_number(char* array){
    int result=0;
    while(*(++array)!='\0'){
        if(*array>='0'&&*array<='9'){
            result=result*10;
            result+=int((*array)-48);
        }
    }
    return result;
}
