//find the longest subarray with the given sum --> length of the longest subarray
//url: https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

// APPROACH:prefix sum
/*
using the approach i.e: total sum = sum of first part of array + sum of second part of array
represented by : sum = k + x;

traverse the array:
  calculate the prefix sum till ith index
  if sum till ith element == 0 then set length = i+1 (where i is the index)
  else check if x (x = sum-k) is present in the map : 
      if yes then calculate the length by getting the max of (i - m[x]) --> i is the current index and m[x] is the index sum of the x part of the array
      if no then push the sum in the array with val as the index
*/
// since here k = 0 so x = sum thats why taken sum directly without using another name x

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
         int count=0,sum=0,k=0;
        //map where key = sum and value = index till which the sum is calculated
        map<int,int>m;
        for(int i=0;i<A.size();i++){
            //calculate the pre fix sum till ith element
            sum+=A[i];
            
            //if the sum of all the elements till ith index gives u the required sum
            //then the max length of the sub array is i+1 since i starts from 0
            if(sum == k) count= i+1;
            
            else{
                //the sum already exist in the map then
                if(m.find(sum)!=m.end()){
              // WE find the maximum length by i-m[sum] --> i is the current index and m[sum] is the index of 
              //pre fix sum
                    count = max(count, i-m[sum]);
                }
                else
                //we insert the sum in the map with the index
                    m[sum]=i;
            }
        }
    return count;
    }
};


//T.C : O(N log N) --> N to traverse the array and log N to insert in map
//S.C : O(N)
