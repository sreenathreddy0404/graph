#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(vector<vector<int>> &adj,vector<bool> &visited,stack<int> &s,int node){
        visited[node] = true;
        for(auto neigh:adj[node]){
            if(!visited[neigh]){
                dfs(adj,visited,s,neigh);
            }
        }
        s.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        //topoSort Works only on Directed ACyclic Graph (DAG)
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
        }
        
        stack<int> st;
        vector<bool> visited(V,false);
        for(int i = 0;i<V;i++){
            if(!visited[i]){
                dfs(adj,visited,st,i);
            }
        }
        
        vector<int> ans;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            ans.push_back(node);
        }
        
        return ans;
    }
};

int main(){
    return 0;
}