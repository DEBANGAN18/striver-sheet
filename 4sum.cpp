// Find unique quadraples whose sum = k
//URL: https://leetcode.com/problems/4sum

//APPROACH: sort the array
/*fix a with i loop
then use 3sum approach by fixing b with j loop
and lastly for last 2 nos, use the 2sum approach with the help of 2 pointers
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        int n=nums.size();
        
        //sorting the array
        sort(nums.begin(),nums.end());
        
        //fixing a = nums[i];
        for(int i=0;i<n-3;i++){
            
            //since we previously checked for nums[i] so we skip the check for duplicate value
            if(i>0 and nums[i]==nums[i-1]) continue;
            
                //handling the overflow by type casting to long long
                 long long suma = k-nums[i]*1L;
            
                //fixing b = nums[j];
                for(int j=i+1;j<n-2;j++){
                    
                    //since we previously checked for nums[j] so we skip the check for duplicates
                    if(j>i+1 and nums[j]==nums[j-1]) continue;
                    
                        long long sumb = suma-nums[j];
                        int s=j+1,e=n-1;
                    
                        while(s<e){
                            if(nums[s]+nums[e]==sumb){
                                ans.push_back({nums[i],nums[j],nums[s],nums[e]});
                                
                                //checking duplicates for nums[s] and nums[e] and skipping it
                                while(s<e and nums[s]==nums[s+1])s++;
                                while(s<e and nums[e]==nums[e-1])e--;   
                                s++;
                                e--;
                            }
                            else if(nums[s]+nums[e]<sumb) s++;
                            else e--;
                        }
                    }
        }
        return ans;
    }
  
  
  //T.C : O(N*N*N)
  //S.C : O(1)
