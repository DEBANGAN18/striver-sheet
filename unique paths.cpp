// start at [0][0] reach [m][n] --> find all the unique paths 
//moves possible are DOWN or RIGHT

//URL: https://leetcode.com/problems/unique-paths/

//APPROACH: not optimised but solved the problem using recursion --> time complexity is exponential
// DP TO BE LEARNT 


class Solution {
public:
    
    int findPath(int i, int j,int m, int n){
        //successfully reached destination
        if(i==m-1 and j==n-1)return 1;
        
        //robot out of boundary
        else if((i>=m) or (j>=n)) return 0;
        
        //down
        /*int newi = i+1;
        int newj = j;
        
        //right
        newi = i;
        newj = j+1;*/
        
        //bottom fuunc call  + right func call --> draw the recursion tree, for every
        //possible move we return one i.e for every path we return 1.
        else return  findPath(i+1,j,m,n)+findPath(i,j+1,m,n);
    }
    
    int uniquePaths(int m, int n) {
        int i=0,j=0,count=0;
        count = findPath(i,j,m,n);
        return count;
    }
};
