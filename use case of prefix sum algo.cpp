// count the number of subarrays whose Sum Equals K
//url :   https://leetcode.com/problems/subarray-sum-equals-k/

// TUTORIAL VDO : https://www.youtube.com/watch?v=XjP2mQr98WQ

//APPROACH: WE USE THE CONCEPT OF PREFIX SUM.
/*
  SAY SUM = SUM OF TILL I ELEMENTS 
  K = TARGET SUM OF A SUB ARRAY
  X + K = SUM => X = SUM - K
  SO WE TRAVERSE THE ARRAY AND CALCULATE THE 'SUM' 
  AND PUSH ALL THE SUM VALUES IN A MAP
  THEN FIND IF X IS IN MAP (X = SUM - K)
  IF X IS IN THE MAP THAT MEANS THERE EXIST A SUB ARRAY WITH SUM K 
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0,sum=0;
        //map where key = sum and value = frequency of sum
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            
            if(sum == k)count++;
            int x = sum-k;
            
            //sum(total length) - k = x --> if x is present in the map then there exist a sub-array with sum = k
            if(m.find(x)!=m.end()){
              // WE INCREMENT BY COUNT BY ADDING IT TO THE FREQUENCY OF THE X, SAY K = 9 AND SUM = 13 SO X = 4, THERE EXIST TWO 4 THUS COUNT OF SUB ARRAY IS ALSO 2. 
                count = m[x]+count;
            }
            
            //if sum exists in map then increase the frequency otherwise introduce in map with 1 frequency
            if(m.find(sum)!=m.end())
                m[sum]++;
            else
                m[sum]=1;
        }
    return count;
    }
};


//T.C : O(N)
//S.C : O(N)
