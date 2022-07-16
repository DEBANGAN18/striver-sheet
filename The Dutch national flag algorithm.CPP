// SORT 0,1,2
// URL: https://leetcode.com/problems/sort-colors/

/*APPROACH: GET THE COUNT OF 0,1,2 BY TRAVERSING THE ARRAY
REPLACE THE FIRST C0 ELEMENTS WITH 0, THEN C1 ELEMENTS BY 1 AND C2 ELEMENTS BY 2*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //counter for 0,1,2;
        int count_0 = 0, count_1 = 0, count_2 = 0;
        
        //get the count of 0,1,2
        for(auto i:nums){
            if(i == 0) count_0++;
            if(i == 1) count_1++;
            if(i == 2) count_2++;
        }
        //replace the array elements with 0,1,2 as per range of count_0,count_1,count_2
        for(int i=0; i<nums.size();i++){
            //0 to (count_0-1) --> 0  --> zero based index in array
            if(i<count_0) nums[i]=0;
            //count_0 to (count_1-1) --> 1
            else if(i>=count_0 and i<(count_0+count_1)) nums[i]=1;
            //count_1 to (count_2-1) --> 2
            else nums[i]=2;
        }
    }
};

//T.C: O(N)
//S.C: O(1)
