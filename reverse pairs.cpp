//Given an integer array nums, return the number of reverse pairs in the array.
//A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].


//URL: https://leetcode.com/problems/reverse-pairs/


//kind of brute force
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if(nums.size()<2) return 0;
        long long s =0, e= nums.size()-1,count=0;
        for(;e>=0;e--){
            while(s<e){
                long long twice = 2* (long long)nums[e];
                if(nums[s]>twice){
                    count++;
                    s++;
                }
                else if(nums[s]<= twice) s++;
            }
            s=0;
        }
        return count;
    }
};

//optimised appproach: using merge sort where the merging conditon has a logic to select the pairs
