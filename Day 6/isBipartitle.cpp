#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool check(vector<vector<int>> &adj,vector<int> &visited,int node,int color){
        visited[node] = color;
        for(auto neigh:adj[node]){
            if(visited[neigh] == -1){
                if(!check(adj,visited,neigh,1-color))return false;
            }else if(visited[neigh] == color){
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> visited(V,-1);
        
        for(int i=0;i<V;i++){
            if(visited[i] == -1){
                if(!check(adj,visited,i,0)){
                    return false;
                }
            }
        }
        return true;
    }
};