//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
     pair<int,int> ans = {-1,-1};
    int small, big;
    small = INT_MIN;
    big = INT_MAX;
    
    for(int i=0;i<n;i++){
        if(arr[i] == x){
            ans.first=arr[i];
            ans.second=arr[i];
            break;
        }
        else if(arr[i]<x){
            small = max(small, arr[i]);
            ans.first=small;
        }
        else{
            big = min(big,arr[i]);
            ans.second=big;
        }
    }
    return ans;
}