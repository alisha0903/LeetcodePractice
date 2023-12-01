//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

 class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int src,vector<int> &pathVisited,vector<int> adj[],vector<int> &visited){
        
        for(auto &x:adj[src]){
            if(!visited[x]){
                visited[x]=true;
                pathVisited[x]=true;
                if(dfs(x,pathVisited,adj,visited))return true;
                pathVisited[x]=false;
            }
            else if(pathVisited[x]){
                return true;
            }
        }
        
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                visited[i]=true;
                vector<int> pathVisited(V,false);
                pathVisited[i]=true;
                if(dfs(i,pathVisited,adj,visited)) return true;
            }
        }
        
        return false;
    }

};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends