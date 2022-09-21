#include <iostream>
#include <vector>
using namespace std;
class solution{
public:
    static vector<int> twoSum(vector<int>&nums, int target){
        int i,j;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return{i,j};
    }
};
int main(){
    vector<int> a;
    for(int i=0;i<10;i++){
        int b;
        cin >> b;
        a.push_back(b);
    }
    solution::twoSum(a,7);
}