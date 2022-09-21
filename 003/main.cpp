#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    static int lengthOfLongestSubstring(string s) {
        if(s==""){
            return 0;
        }
        int maximum=1;
        int left_border=0;
        int right_border=1;
        int check=0;
        while(right_border!=s.length()+1){
            if(!if_twice(s.substr(left_border,right_border-left_border))){
                check+=1;
                right_border=right_border+1;
            }else{
                if(check>maximum){
                    maximum=check;
                }check=0;
                for(int i=left_border;i<right_border;i++){
                    if(s[i]==s[right_border-1]){
                        left_border=i+1;check=right_border-left_border;right_border=right_border+1;break;}
                }
            }
        }
        if(check>maximum){
            maximum=check;
        }
        cout << maximum;
        return maximum;
    }
    static bool if_twice(string s){
        int len=s.length();
        for(int i=0;i<len-1;i++){
            if(s[i]==s[len-1]){
                return true;
            }
        }
        return false;
    }
};
int main (){
    string str;
    cin >> str;
    Solution::lengthOfLongestSubstring(str);
}
