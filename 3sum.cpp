// find all triplets whose sum is 0 (a[i]+a[j]+a[k] = 0 )such that i != j != k
//and all the triplets are unique

//URL: https://leetcode.com/problems/3sum

//APPROACH: sort the array and use two pointer
/*
general intuition is we fix the first number of (a+b+c = 0) i.e fix A with a loop and see if B and C exist in the array. equation to check is B+C = -A.
so first sort the array and implememt the intuition as mentioned
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      //sort the array
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
      
        //fix the first element such that nums[i]= nums[j]+num3;
        for(int i=0;i<nums.size();i++){
          
          //this if is to check for unique elemets. eg array is [0,1,1,1,2,-1] -> i will be 0 for first iteration and then i=1 for second iteration but i=1 for 
          //third iteration and forth also will be skipped as they are a duplicate value then i=2 and so on.
            if(i==0 || (i>0 and nums[i] != nums[i-1])){
              
              //setting sum as the -nums[i]
                int sum = -nums[i];
              //s and e are two pointers start = i+1 and end = last elemet 
                int s= i+1, e=nums.size()-1;
                while(s<e){
                  
                  //if we get the sum, add it in ans vector with the 3 values.
                    if(nums[s]+nums[e] == sum){
                        ans.push_back({nums[i],nums[s],nums[e]});
                      
                      //if start is pointing to a duplicate element element, we skip it and increment start till the time when start has a unique value
                      //say [0,1,1,1,2,-1] start = 2nd index i.e second 1 thus, its a duplicate value amd we skip it and in next iteration start = 3rd index
                      //i.e 3rd 1 and same goes for end pointer.
                        while(s<e and nums[s]==nums[s+1]) s++;
                        while(s<e and nums[e]==nums[e-1]) e--;
                      //after the while loop, start = 3rd index and to move to new unique element we increment the start and same goes for end
                        s++;
                        e--;
                    }
                  //if sum is less than target then increment start
                    else if(nums[s]+nums[e] < sum) s++;
                    else e--;
                }
            }
        }
        return ans;
    }
};



//T.c : O(N*N) : QUESTION:  the outside for loop runs for approx N times and inner while for the 2 pointer approach its also taken as N times 
/*so what about the other two inner while loops? for skipping duplicates? why is that not calculated 
as part of the time complexity? 
ANS : BECAUSE THEY ARE NOT NESTED, I.E THE WHILE LOOPS WILL EXECUTE IN SPECIAL CASES*/

//S.C : O(1) --> VECTOR<VECTOR<INT>> ANS IS A AUXILARY SPACE FOR ANS, IT DOESNT TAKE PART IN CALCULATION SO ITS ONLY O(N)
