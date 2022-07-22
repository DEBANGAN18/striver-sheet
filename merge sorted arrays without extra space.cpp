//implement power function --> pow(x,n) = x ^ n;
//URL: https://leetcode.com/problems/powx-n/

//APPROACH : 
/*eg: x= 2 and n= 10
2^10 = (2 x 2)^5 = 4^5
4^5 = 4 x 4^4
4^4 = (4 x 4)^2 = 16^2
16^2 = (16 x 16)^1 = 256^1
256^1 = 256 x (256)^0

so we observe that 
1) if power is even --> we multiply no * no and divide power/2
2) if power is odd --> we multiply ans * no and decrease power by 1
*/

class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long nn= n;
      //power is negetive --> convert to positive  
      if(nn<0) nn = -1 * nn;
        while(nn){
          //odd power
            if(nn % 2 != 0){
                ans = ans * x;
                nn = nn-1;
            }
          //even power
            else{
                x = x * x;
                nn = nn/2;
            }
        }
      //if power is negetive
        if(n<0) ans = (double)(1.0)/(double)(ans);
        return ans;
       
    }
};


//T.C: O(log2 n)
///S.C: O(1)
