#include <iostream>
#include <algorithm>
#include <limits>
#include <string>
using namespace std;
int main() {//word count
    char current;
    char previous=' ';
    int char_num=0;
    int word_num=0;
    int line_num=0;
    while((current=cin.get())!='g'){
        char_num+=1;
        if(!((current>='a'&&current<='z')||(current>='A'&&current<='Z')))
        {
            if(current==' '){
                if(previous!=' '&&previous!='\n'){
                    word_num+=1;
                }
            }
            if(current=='\n'){
                line_num+=1;
                if(previous!=' '&&previous!='\n'){
                    word_num+=1;
                }
            }
        }
        previous=current;
    }

    cout << char_num;
    cout << " ";
    cout << word_num;
    cout << " ";
    cout << line_num;

}
