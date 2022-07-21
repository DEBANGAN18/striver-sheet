//TRAPPING RAINWATER
//URL: https://leetcode.com/problems/trapping-rain-water


//BRUTE FORCE: 
//APPROACH: make an array containing the left max values for ith element and same for right maximum values
//volume of water stored in ith element = (minimum of(left max and right max) - the element)
class Solution {
public:
    int trap(vector<int>& height) {
        int maxl = -1;
        int maxr = -1;
        int n = height.size();
        int left[n];
        int right[n];

        //left: contains the left maximum values for a particular i
        for(int i=0;i<n;i++){ 
            maxl = max(maxl, height[i]);
            left[i] = maxl;
            
        }
        
        //right: contains the left maximum values for a particular i
        for(int i=n-1;i>=0;i--){ 
            maxr = max(maxr, height[i]);
            right[i]= maxr;
        }
        
        //calculating the volume
        int ans = 0;
        for(int i=0;i<n;i++){
            ans+= (min(left[i],right[i])-height[i]);
        }
        return ans;
    }
};

//T.C: O(N)
//S.C: 0(N+N)
