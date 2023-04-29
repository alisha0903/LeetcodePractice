//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
   int prec(char op) {
        switch(op) {
            case '(': return 0;
            case '-': return 1;
            case '+': return 1;
            case '*': return 2;
            case '/': return 2;
            case '^': return 3;
        }
        return 3;
    }
    string infixToPostfix(string str) {
        // Your code here
        stack<char>st;
        string res;
        for(int i=0;i<str.length();i++)
        {
            if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
            res+=str[i];
            
            else if(str[i]=='(')
            st.push(str[i]);
            
            else if(str[i]==')')
            {
             while(!st.empty() &&st.top()!='(')
             {
                res+=st.top();
                st.pop();
             }
            if(!st.empty())
              st.pop();  
            } 
            else {
                while(!st.empty()&&prec(st.top())>=prec(str[i]))
                {
                    res+=st.top();
                    st.pop();
                }
                st.push(str[i]);
            } 
        }
                while(!st.empty())
                {
                    if(st.top()=='(')
                    st.pop();
                    res+=st.top();
                    st.pop();
                }
            
            
    
        return res;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends