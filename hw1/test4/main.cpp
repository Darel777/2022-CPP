#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    int a[1000];
    for(int i=0;i<1000;i++){
        a[i]=2022;
    }
    int b[1000];
    for(int i=0;i<1000;i++){
        b[i]=0;
    }
    int poi=0;
    int c;
    char ch;
    cin >> c;
    while(1){
        int exist=0;
        for(int i=0;i<poi;i++){
            if(c==a[i]){
                b[i]=1;exist=1;
            }
        }
        if(!exist){
            a[poi++]=c;
        }
        ch=cin.get();
        if(ch==EOF){
            break;
        }
        cin>>c;
    }
    for(int i=0;i<1000;i++){
        if(b[i]==0){
            cout << a[i];
            break;
        }
    }

}
