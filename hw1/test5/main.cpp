#include <iostream>
#include <string>
using namespace std;
string int_to_binary(int n);
int binary_to_int(string s);
int main() {
    static const char base64_alphabet[] = {
            'A', 'B', 'C', 'D', 'E', 'F', 'G',
            'H', 'I', 'J', 'K', 'L', 'M', 'N',
            'O', 'P', 'Q', 'R', 'S', 'T',
            'U', 'V', 'W', 'X', 'Y', 'Z',
            'a', 'b', 'c', 'd', 'e', 'f', 'g',
            'h', 'i', 'j', 'k', 'l', 'm', 'n',
            'o', 'p', 'q', 'r', 's', 't',
            'u', 'v', 'w', 'x', 'y', 'z',
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            '+', '/'};
    string result= "";
    char in_stream[100000];
    int poi=0;
    char temp;
    while((temp=cin.get())!='p'){
        in_stream[poi]=temp;
        poi=poi+1;
    }
    in_stream[poi]=EOF;

    for(int i=0;i<poi;i+=3){
        if(in_stream[i]!=EOF&&in_stream[i+1]!=EOF&&in_stream[i+2]!=EOF){
            int a1=in_stream[i];
            int a2=in_stream[i+1];
            int a3=in_stream[i+2];
            string temp="";
            temp= int_to_binary(a1)+ int_to_binary(a2)+ int_to_binary(a3);
            int b1= binary_to_int(temp.substr(0,6));
            int b2= binary_to_int(temp.substr(6,12));
            int b3= binary_to_int(temp.substr(12,18));
            int b4= binary_to_int(temp.substr(18,24));
            result=result+base64_alphabet[b1]+base64_alphabet[b2]+base64_alphabet[b3]+base64_alphabet[b4];
        }else if(in_stream[i]!=EOF&&in_stream[i+1]!=EOF&&in_stream[i+2]==EOF){
            int a1=in_stream[i];
            int a2=in_stream[i+1];
            string temp="";
            temp= int_to_binary(a1)+ int_to_binary(a2);
            temp=temp+"00";
            int b1= binary_to_int(temp.substr(0,6));
            int b2= binary_to_int(temp.substr(6,12));
            int b3= binary_to_int(temp.substr(12,18));

            result=result+base64_alphabet[b1]+base64_alphabet[b2]+base64_alphabet[b3]+"=";
        }else if(in_stream[i]!=EOF&&in_stream[i+1]==EOF){
            int a1=in_stream[i];
            string temp="";
            temp= int_to_binary(a1);
            temp= temp.substr(0,6)+temp.substr(6,8)+"0000";
            int b1= binary_to_int(temp.substr(0,6));
            int b2= binary_to_int(temp.substr(6,12));
            result=result+base64_alphabet[b1]+base64_alphabet[b2]+"==";
        }
    }
    cout << result;
    return 0;
}
string int_to_binary(int n){
string result="";
while(n!=0){
if(n%2==1){
    result="1"+result;

}else{
    result="0"+result;
}
n/=2;
}
if(result.length()==1){
    result="0000000"+result;
}else if(result.length()==2){
    result="000000"+result;
}else if(result.length()==3){
    result="00000"+result;
}else if(result.length()==4){
    result="0000"+result;
}else if(result.length()==5){
    result="000"+result;
}else if(result.length()==6){
    result="00"+result;
}else if(result.length()==7){
    result="0"+result;
}
    return result;
}
int binary_to_int(string s){
    int result=0;
    if(s[0]=='1'){
        result+=32;
    }
    if(s[1]=='1'){
        result+=16;
    }
    if(s[2]=='1'){
        result+=8;
    }
    if(s[3]=='1'){
        result+=4;
    }
    if(s[4]=='1'){
        result+=2;
    }
    if(s[5]=='1'){
        result+=1;
    }
    return  result;
}

