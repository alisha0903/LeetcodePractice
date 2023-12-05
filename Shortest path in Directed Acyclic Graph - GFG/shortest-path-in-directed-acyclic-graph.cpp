//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void sort(int i,vector<int> & toposort,vector<pair<int,int>>  adj[],vector<int> & visited)
     {
         visited[i]=1;
         for(auto x: adj[i])
         {
             if(visited[x.first]==1)
             continue;
             sort(x.first,toposort,adj,visited);
         }
         toposort.push_back(i);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        vector<pair<int,int>>  adj[N];
        for(auto x: edges)
        {
            int u=x[0];
            int v=x[1];
            int w=x[2];
            adj[u].push_back({v,w});
        }
        vector<int> toposort;
        vector<int> visited(N,0);
        for(int z=0;z<N;z++)
        {
            if(visited[z]==0)
            sort(z,toposort,adj,visited);
            
        }
        reverse(toposort.begin(),toposort.end());
        
        int itr=0;
        vector<int> cost (N,-1);
        cost[0]=0;
        while(itr<N)
        {
           int ele=toposort[itr];
           itr++;
          
           for(auto hkp:adj[ele] )
           {
               if(cost[ele]==-1)
               continue;
               
               if(cost[hkp.first]==-1||cost[hkp.first]>cost[ele]+hkp.second)
               cost[hkp.first]=cost[ele]+hkp.second;
           }
           
        }
        return cost;
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends