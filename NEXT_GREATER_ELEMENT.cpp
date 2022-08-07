//find the next greater element / next largest element in the right
//URL: https://leetcode.com/problems/next-greater-element-i/

/**********************************************LEETCODE SOLUTION**********************************/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      stack<int>temp;
	    vector<int>a;
        map<int,int>ans;
        
        int n = nums2.size();
	    //traversing the array from back 
	    for(int i=n-1;i>=0;i--){

	    	//if stack is empty i.e size == 0  
	    	if(temp.size()==0){
	    		ans[nums2[i]]=-1;
	    	}

		    //if stack top is > element then push it in ans
	    	else if(temp.size()>0 and temp.top()>nums2[i]){
	    			ans[nums2[i]]=temp.top();
	    	}

	    	// if stack top is < element POP the top till (stack is empty OR top > element) 
		    else if(temp.size()>0 and temp.top()<nums2[i]){
                while(temp.size()>0 and temp.top()<nums2[i])
	    			temp.pop();

	    		if(temp.size()==0)
	    			ans[nums2[i]]=-1;
	    		else
	    			ans[nums2[i]]=temp.top();
		    }
	    	
		    //before i goes to the next element add the current element in the stack
		    temp.push(nums2[i]);
		    }
            
            for(int i:nums1){
                a.push_back(ans[i]);
            }
            return a;
        }
};




/********************************************************* PARENT CODE *****************************************************/
#include <bits/stdc++.h> 
#include <algorithm>
using namespace std;

void display(vector<int>ans){
	int n = ans.size();
	cout<<"ans:"<<" ";
	for(int i=n-1;i>=0;i--)
		cout<<ans[i]<<" ";
	cout<<endl;
}

void nge(vector<int> arr, int n ){
	stack<int>temp;
	vector<int>ans;

	//traversing the array from back 
	for(int i=n-1;i>=0;i--){

		//looping to check if the stack has the nge element or not, if yes the push to ans vector and break
		//else pop all the elements which are smaller than the current element
		
		//if stack is empty i.e size == 0  
		if(temp.size()==0){
			temp.push(-1);
			ans.push_back(-1);
		}

		//if stack top is > element then push it in ans
		else if(temp.size()>0 and temp.top()>arr[i]){
				ans.push_back(temp.top());
		}

		// if stack top is < element POP the top till (stack is empty OR top > element) 
		else if(temp.size()>0 and temp.top()<arr[i]){
			while(temp.size()>0 and temp.top()<arr[i])
				temp.pop();

			if(temp.size()==0)
				ans.push_back(-1);
			else
				ans.push_back(temp.top());
		}
		
		//before i goes to the next element add the current element in the stack
		temp.push(arr[i]);
		}

	display(ans);
}

int main()
{
    vector<int> arr = {1,3,0,5,2,4,6};
    //vector<int> end = {3,5,5,6,4,6,-1};
    int n = arr.size();
    nge(arr, n);
    return 0;
}


//T.C: I got what you want to ask:-
/*your main concern is about the inside while() loop, you are thinking that it will become O(n^2)  , but this will never happen  the worst case complexity can be O(2n) , in simple terms O(n) . 
Case 1 :-
arr [] :- 6 5 4 3 2 1
In this case the while() loop will run only one time in each iteration of  for() loop so, while() loop is contributing only O(1) complexity. 
In this case it is simple O(n). 

Case 2:-
are[]:- 6 1 2 3 4 5

In this case every element in the array will considered 2 times. 
First time when we are traversing the array in backward direction through for() loop and another time when we traverse element in forward direction through while() loop. 
It is just like traversing array two times 
O(n) +O(n) =O(2*n). 
So, 
The overall complexity  become O(2n)  ~ O(n).
*/

//S.C: O(N)
