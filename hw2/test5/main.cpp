#include <iostream>
#include <cstdint>
using namespace std;
int find_right(char* array,int current);
int find_left(char* array,int current);

int main() {
    int pointer_array=0;//指向数组的指针
    int pointer_instr=0;//指向BF程序的指针

    char array[1000];for(int i=0;i<1000;i++){array[i]=0;}//全部初始化为0且大小无限的数组
    char instr[1000];//第一行为BF程序，instr用来存储BF程序


    cin.getline(instr,1000);

    while(instr[pointer_instr]!='\0'&&instr[pointer_instr]!=EOF){
        if(instr[pointer_instr]=='>'){
            pointer_array+=1;
        }else if(instr[pointer_instr]=='<'){
            pointer_array-=1;
        }else if(instr[pointer_instr]=='+'){
            array[pointer_array]+=1;
        }else if(instr[pointer_instr]=='-'){
            array[pointer_array]-=1;
        }else if(instr[pointer_instr]==','){
            char c;
            uint8_t  byte=1;
            if(!cin.get(c)){
                byte=0;
            }

            if(byte==1){
                array[pointer_array]=c;
            }else{
                array[pointer_array]=0;
            }

        }else if(instr[pointer_instr]=='.'){
            cout << array[pointer_array];
        }else if(instr[pointer_instr]=='['){
            if(array[pointer_array]==0){
                int b= find_right(instr,pointer_instr);
                pointer_instr+=b;
            }
        }else if(instr[pointer_instr]==']'){
            if(array[pointer_array]!=0){
                int b= find_left(instr,pointer_instr);
                pointer_instr-=b;
            }
        }
        pointer_instr+=1;
    }
    return 0;
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