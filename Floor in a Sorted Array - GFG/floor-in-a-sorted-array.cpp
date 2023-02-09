//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
            if(x == 0){
            return -1;
        }
        int lo=0;
        int hi=n-1;
        int mid = (lo+hi)/2;
        int index = -1;
        while(lo<=hi){
            if(x>v[mid]){
                lo=mid+1;
                mid = (lo+hi)/2;
                index = mid;
            }
            else if(x == v[mid]){
                return mid;
            }
            else{
                hi = mid-1;
                mid = (lo+hi)/2;
            } 
        }
        return index;
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends