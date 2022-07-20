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
//approach is same as implementation of merge sort only the counting portion is added extra where the counting of pairs is done before merging the sub-parts and are 
//added to the count var in mergeS() function.

class Solution {
public:
   
    int merge(vector<int>& nums, int s,int m, int e){
        int count =0;
        int secondhalf = m+1;
     
        //counting the pairs
        for(int firsthalf = s; firsthalf <= m;  firsthalf++){
            while(secondhalf<=e and nums[firsthalf] >2* (long long) nums[secondhalf]){
                secondhalf++;
            }
            // say in the second half of the array there are [2,4,6,8] and secondhalf is pointing to 6 that means--> 2 and 4 should be involved for counting as pairs
            //that means. we count the left elements of secondhalf. (second part of the array starts from m+1) 
             count += (secondhalf - (m + 1));
        }
        
        //sorting the subparts like merge sort functionality
        int i=s,j=m+1;
        vector<int>temp;
        while(i<=m and j<=e){
            if(nums[i]> nums[j]){
                temp.push_back(nums[j]);
                j++;
            }
            else{
                temp.push_back(nums[i]);
                i++;
            }
        }
        while(j<=e) temp.push_back(nums[j++]);
        while(i<=m) temp.push_back(nums[i++]);
        
        //copying the sorted array back to nums
        int k=0;
        for(int i=s;i<=e;i++){
            nums[i]=temp[k++];
        }
        return count;
    }
    int mergeS(vector<int>& nums, int s, int e){
        //base case
        if(s>=e) return 0;
         
        //recursion
        int mid = (s+e)/2;
        
        //mergesort on first half
        int count = mergeS(nums,s,mid);
        
        //mergesort on second half    
        count+= mergeS(nums,mid+1,e);
        
        //merge the sub-parts
        count+= merge(nums,s,mid,e);
        
         return count;
    }
    
    int reversePairs(vector<int>& nums) {
       
        int s=0,e=nums.size()-1;
        return mergeS(nums,s,e); 
    }
};
//T.C: O(N LOG N) {FOR MERGE SORT } + O(N) {COUNTING PAIRS} + O(N){MERGING THE SUB PARTS}
//S.C: O(N) --> USING TEMP ARRAY
