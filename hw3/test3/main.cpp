#include <iostream>
#include <cctype>
#include <string>
using namespace std;
void default_mode(string* a,int num);
void digit_mode(string* a,int num);
void rotate_mode(string* a,int num);
void ignore_mode(string* a,int num);
void depart_mode(string* a,int num);
int to_int(string a);
int main() {
    int N;cin >> N;cin.get();string a[N];
    for(int i=0;i<N;i++){
        getline(cin,a[i]);
    }
    int modes;cin >> modes;cin.get();char b[modes];
    for(int i=0;i<modes;i++){
        cin >> b[i];cin.get();
    }

    for(int i=0;i<modes;i++){
        if(b[i]=='-'){
            default_mode(a,N);//默认
        }else if(b[i]=='n'){
            digit_mode(a,N);//纯数字
        }else if(b[i]=='i'){
            ignore_mode(a,N);//忽略大小写
        }else if(b[i]=='d'){
            depart_mode(a,N);//只比较字母数字空格
        }else if(b[i]=='r'){
            rotate_mode(a,N);//逆序
        }
    }
    return 0;
}
void default_mode(string* a,int num){
    string b[num];
    for(int i=0;i<num;i++){
        b[i]=a[i];
    }
    string temp;
    for(int i=0;i<=num-2;i++){
        for(int j=i+1;j<=num-1;j++){
            if(b[j]<b[i]){
                temp=b[j];
                b[j]=b[i];
                b[i]=temp;
            }
        }
    }
    for(int i=0;i<num;i++){
        cout << b[i] << endl;
    }
}
void digit_mode(string* a,int num){
    int b[num];
    for(int i=0;i<num;i++){
        b[i]=to_int(a[i]);
    }
    int temp;
    for(int i=0;i<=num-2;i++){
        for(int j=i+1;j<=num-1;j++){
            if(b[j]<b[i]){
                temp=b[j];
                b[j]=b[i];
                b[i]=temp;
            }
        }
    }
    for(int i=0;i<num;i++){
        cout << b[i] << endl;
    }
}
void rotate_mode(string* a,int num){
    string b[num];
    for(int i=0;i<num;i++){
        b[i]=a[i];
    }
    string temp;
    for(int i=0;i<=num-2;i++){
        for(int j=i+1;j<=num-1;j++){
            if(b[j]<b[i]){
                temp=b[j];
                b[j]=b[i];
                b[i]=temp;
            }
        }
    }
    for(int i=num-1;i>=0;i--){
        cout << b[i] << endl;
    }
}
void ignore_mode(string* a,int num){
    string b[num];
    string c[num];
    for(int i=0;i<num;i++){
        b[i]=a[i];
    }for(int i=0;i<num;i++){
        c[i]=a[i];
    }
    for(int i=0;i<num;i++){
        for(int j=0;b[i][j]!='\0';j++){
            b[i][j]= tolower(b[i][j]);
        }
    }
    string temp;
    for(int i=0;i<=num-2;i++){
        for(int j=i+1;j<=num-1;j++){
            if(b[j]<b[i]){
                temp=b[j];b[j]=b[i];b[i]=temp;
                temp=c[j];c[j]=c[i];c[i]=temp;
            }
        }
    }
    for(int j=0;j<num-1;j++){
        for(int i=0;i<num-1;i++){
            if(c[i].length()==c[i+1].length()){
                int swi=0;
                for(int j=0;j<c[i].length();j++){
                    if(c[i+1][j]-c[i][j]==-32||c[i+1][j]-c[i][j]==0||c[i+1][j]-c[i][j]==32){
                        swi=swi+1;
                    }
                }
                if(swi==c[i].length()){
                    if(c[i]>c[i+1]){
                        temp=c[i+1];
                        c[i+1]=c[i];
                        c[i]=temp;
                    }
                }
            }
        }}
    for(int i=0;i<num;i++){
        cout << c[i] << endl;
    }
}
void depart_mode(string* a,int num){
    string b[num];
    string c[num];
    for(int i=0;i<num;i++){
        b[i]=a[i];
    }for(int i=0;i<num;i++){
        c[i]=a[i];
    }
    for(int i=0;i<num;i++){
        for(int j=0;b[i][j]!='\0';j++){
            if(!((b[i][j]>='a'&&b[i][j]<='z')||(b[i][j]>='A'&&b[i][j]<='Z')||(b[i][j]==' ')||(b[i][j]>='0'&&b[i][j]<='9'))){
                for(int k=j;;k++){
                    b[i][k]=b[i][k+1];
                    if(b[i][k]=='\0'){
                        break;
                    }
                }
                j=j-1;
            }
        }
    }
    string temp;
    for(int i=0;i<=num-2;i++){
        for(int j=i+1;j<=num-1;j++){
            if(b[j]<b[i]){
                temp=b[j];b[j]=b[i];b[i]=temp;
                temp=c[j];c[j]=c[i];c[i]=temp;
            }
        }
    }
    for(int i=0;i<num;i++){
        cout << c[i] << endl;
    }
}
int to_int(string a){
    int result=0;
    if(a[0]=='-'){
        for(int i=1;a[i]!='\0';i++){
            result*=10;
            result+=(a[i]-48);
        }
        result=-result;
    }else{
        for(int i=0;a[i]!='\0';i++){
            result*=10;
            result+=(a[i]-48);
        }
    }
    return result;
}