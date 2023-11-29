//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
     private:
    void dfs(int vis[],int start, vector<int> adj[],vector<int> &dfsList)
    {
       vis[start]=1;
       dfsList.push_back(start);
       for(auto p:adj[start]) //neighbors
       {
           if(!vis[p]) dfs(vis,p,adj,dfsList);
       }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
        // Code here
        int vis[n]={0};
        int start=0; //start node=0;
        vector<int> dfsList;
        dfs(vis,start,adj,dfsList);
        return dfsList;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends