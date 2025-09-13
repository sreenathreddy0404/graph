#include<bits/stdc++.h>
using namespace std;


bool detectCycle(vector<vector<int>> &adj,vector<bool> &visited,int node){
    queue<pair<int,int>> q;
    q.push({node,-1});
    visited[node] = true;
    while(!q.empty()){
        auto current = q.front();
        int n = current.first;
        int parent = current.second;
        q.pop();
        for(auto neighbour:adj[n]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push({neighbour,n});
            }else if(neighbour != parent)return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    int E = edges.size();
    for(int i=0;i<E;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    
    vector<bool> visited(V,false);
    int parent = -1;
    
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(detectCycle(adj,visited,i))return true;
        }
    }
    return false;
}


int main() {
    int V = 5, E = 5;
    vector<vector<int>> adj(V);
    vector<vector<int>> edges = {{0,1},{1,2},{1,4},{2,3},{3,4}};
   
    if(isCycle(V,edges)) cout<<"Cycle is detected";
    else cout<<"No cycle detected";
    return 0;
}