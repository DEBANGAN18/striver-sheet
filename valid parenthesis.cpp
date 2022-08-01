// check if the string has balanced parenthesis :
/*An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.*/


//URL: https://leetcode.com/problems/valid-parentheses


class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        char ch;
        
        //if only one element means unbalanced parenthesis
        if(s.length() == 1) return false;
        
        //storing the elemets in the stack if it is an opening brace
        for(int i=0;i<s.length();i++){
        
            ch = s[i];
            
            //checking for opening brace, if yes push to stack
            if(ch =='(' or ch == '{' or ch == '[')
                st.push(ch);
            
            //for closing brace, if yes check with stack top and pop stack top
            else {
                //proceed if stack is not empty
                if(!st.empty()){
                    //matching case of pairs
                    char top = st.top();
                    if ((ch ==')' and top =='(')
                        or(ch =='}' and top =='{')
                        or(ch ==']' and top =='['))
                    
                            st.pop();
                    
                    //not matching case
                    else
                        return false;
                }
                //stack is empty
                else{
                    return false;
                }
            }
        }
            if(st.empty()) return true;
            else return false;
    }
};


//T.C : O(N) for stack traversal
//S.C : O(N) for using a stack
