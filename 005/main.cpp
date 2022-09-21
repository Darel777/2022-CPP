#include <iostream>
using namespace std;
class Solution {
public:
    static string longestPalindrome(string s) {
        int text=0;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]==s[i+1]){
                text++;
            }
        }
        if(text==s.length()-1){
            return s;
        }
        if(s.length()==1){return s;}
        if(s.length()==0){return "";}
        string result="";
        for(int i=0;i<s.length();i++){
            int z_index=0;
            while(i-z_index>=0&&i+z_index<s.length()){
                string a=getPalindrome(s.substr(i-z_index,2*z_index+1));
                if(a.length()>result.length()){
                    result=a;
                }
                z_index++;
                if(a==""){
                    break;
                }
            }
        }
        for(int i=0;i<s.length()-1;i++){
            int z_index=1;
            if(s[i]==s[i+1]){
                if(result.length()<2){
                    result=s.substr(i,2);
                }
                while(i-z_index>=0&&i+1+z_index<s.length()){
                    string a=getPalindrome(s.substr(i-z_index,2*(z_index+1)));
                    if(a.length()>result.length()){
                        result=a;
                    }
                    if(a==""){
                        break;
                    }
                    z_index=z_index+1;
                }
            }
        }
        return result;
    }
    static string getPalindrome(string s){
        int len=s.length();
        for(int i=0;i<len/2;i++){
            if(s[i]!=s[len-i-1]){
                return "";
            }
        }
        return s;
    }
};
int main() {
    Solution::longestPalindrome("aaaa");
    return 0;
}
