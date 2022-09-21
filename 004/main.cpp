#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        int first_it=0;int second_it=0;
        int a=nums1.size();
        int b=nums2.size();
        if(a==0){
            if(nums2.size()%2==0){
                return double(nums2[nums2.size()/2-1]+nums2[nums2.size()/2])/2;
            }else{
                return double(nums2[nums2.size()/2]);
            }
        }
        if(b==0){
            if(nums1.size()%2==0){
                return double(nums1[nums1.size()/2-1]+nums1[nums1.size()/2])/2;
            }else{
                return double(nums1[nums1.size()/2]);
            }
        }
        int c=0;
        int d=0;
        while(c!=-1||d!=-1){
            if(nums1[first_it]>=nums2[second_it]&&d!=-1){
                nums3.push_back(nums2[second_it]);
                second_it+=1;
            }else if(nums1[first_it]<nums2[second_it]&&c!=-1){
                nums3.push_back(nums1[first_it]);
                first_it+=1;
            }else if(c==-1){
                nums3.push_back(nums2[second_it]);
                second_it+=1;
            }else{
                nums3.push_back(nums1[first_it]);
                first_it+=1;
            }
            if(first_it==a){
                first_it=first_it-1;
                c=-1;
            }
            if(second_it==b){
                second_it=second_it-1;
                d=-1;
            }
        }
        if(nums3.size()%2==0){
            cout << (nums3[nums3.size()/2-1]+nums3[nums3.size()/2])/2;
            return double(nums3[nums3.size()/2-1]+nums3[nums3.size()/2])/2;
        }else{
            cout << nums3[nums3.size()/2];
            return double(nums3[nums3.size()/2]);
        }

    }
};
int main() {
    vector<int> a;
    for(int i=0;i<2;i++){
        int b;
        cin >> b;
        a.push_back(b);
    }
    vector<int> c;
    for(int i=0;i<1;i++){
        int b;
        cin >> b;
        c.push_back(b);
    }
    Solution::findMedianSortedArrays(a,c);
    return 0;
}
