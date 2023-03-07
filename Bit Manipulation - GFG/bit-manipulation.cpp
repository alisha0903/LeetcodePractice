//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int n, int k) {
        // your code here
       cout << (n >> (k-1)) % 2<<" ";
        // for set
        cout<< (n | (1 << (k - 1)))<<" ";
        cout<< (n & (~(1 << (k - 1))))<<" ";
       
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends