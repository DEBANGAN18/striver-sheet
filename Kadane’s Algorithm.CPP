//FIND THE SUBARRAY WITH MAXIMUM SUM

//URL : https://leetcode.com/problems/maximum-subarray/

/*APPROACH : WE TAKE 2 VARIABLES -->  current_sum AND max_sum
TRAVERSE THE ARRAY AND ADD THE SUM OF ELEMENTS IN current_sum
AT EVERY STEP, FIND MAXIMUM SUM BY CHOOSING THE MAX OF current_sum AND max_sum
IF current_sum < 0 --> SET current_sum = 0*/ 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {  
        int current_sum = 0, max_sum = INT_MIN;
        for(int i=0; i<nums.size();i++){
            current_sum += nums[i];
            max_sum = max(max_sum,current_sum);
            if(current_sum < 0) current_sum = 0;
        }
        return max_sum;
    }
};

// T.C: O(N) --> TRAVERSING THE ARRAY ONCE
//S.C : O(1) --> CONSTATNT SPACE
