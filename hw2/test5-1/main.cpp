#include <iostream>
#include <string>
using namespace std;//test two functions below
int find_right(char* array,int current);
int find_left(char* array,int current);
int main() {
    char instr[1000];
    cin.getline(instr,1000);
    cout << find_left(instr,16);

}
int find_right(char* array,int current){
    int remain_count=1;//比如说，在扫描的过程中遇到了【，那么+1，如果遇到了】，那么-1，当remain——count为0时，找到了对应的】。
    int temp=current;
    for(current=current+1;;current++){
        if(*(array+current)=='['){
            remain_count+=1;
        }else if(*(array+current)==']'){
            remain_count-=1;
        }
        if(remain_count==0){
            break;
        }
    }
    return current-temp;
}
int find_left(char* array,int current){
    int remain_count=1;
    int temp=current;
    for(current=current-1;;current--){
        if(*(array+current)=='['){
            remain_count-=1;
        }else if(*(array+current)==']'){
            remain_count+=1;
        }
        if(remain_count==0){
            break;
        }
    }
    return temp-current;
}