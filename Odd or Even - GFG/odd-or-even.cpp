//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string oddEven(int n){
        // code here 
        string res;
         if ((n ^ 1) == (n + 1))
        res="even";
        else res="odd";
        return res;
         
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.oddEven(N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends