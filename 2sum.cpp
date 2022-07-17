//2 sum
// URL: https://leetcode.com/problems/two-sum/

///APPROACH: target = num1 + num2
/*
num1 = nums[i] at ith iteration, so we find is there a num2 in the array such that num2 = target - num1.
we traverse the array
calculate num2
find if num2 is in the map then return the indices of num1 and num2 
then we add the ith element in the map; 
*/

// MAP HAS KEY = NUMS[I] AND VALUE = INDEX
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>m;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
          //calculate num2
            int num2 = target-nums[i];
          
          //find num2 in map, if already present then return the indices
            if(m.find(num2)!=m.end()){
                ans.push_back(i);
                ans.push_back(m[num2]);
                return ans;
            }
          //adding the ith element in the map at ith index.
            m[nums[i]]=i;
        }
        return ans;
    }
};


//T.C : O(N log N)
//S.C : O(N)
