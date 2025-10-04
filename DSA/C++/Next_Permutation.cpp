#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //1. finding pivot column
        int n= nums.size();
        int idx = -1;
        for(int i = n-2 ; i>=0 ; i--){
            if(nums[i]<nums[i+1]){
                idx = i;
                break;
            }
        }
        // if array is already greatest
        if(idx==-1){
            reverse(nums.begin(),nums.end());
            return;  
        }
        //2. sorting/ reverse after point
        reverse(nums.begin()+idx+1, nums.end());

        //3. finding the just greater element thn idx
        int j=-1;
        for( int i = idx +1; i<n; i++){
           if(nums[i]>nums[idx]){
            j=i;
            break;
           }
        }

        //3. swapping idx and j
        int temp = nums[idx];
        nums[idx]=nums[j];
        nums[j]=temp;
        return;
    }
};