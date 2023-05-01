//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        stack<string> st;
        int n=post_exp.size();
        
        for(int i=0;i<n;i++){
            char ch=post_exp[i];
            if(isalpha(ch)){
                string temp;
                temp+=ch;
                st.push(temp);
            }
            else{
                string a=st.top();
                st.pop();
                string b=st.top();
                st.pop();
                st.push(a+b+ch);
                
                
            }
            
        }
        string res= st.top();
        st.pop();
        reverse(res.begin(),res.end());
        return res;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends