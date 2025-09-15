#include<bits/stdc++.h>
using namespace std;

//Using dfs
bool detectCycle(vector<vector<int>> &adj,vector<bool> &visited,vector<int> &pathVisited,int node){
    visited[node] = true;
    pathVisited[node] = true;
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            detectCycle(adj,visited,pathVisited,neighbour);
            pathVisited[neighbour] = false;
        }else if(pathVisited[neighbour])return true;
    }
    return false;
}
bool isCycle(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    int E = edges.size();
    for(int i=0;i<E;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        //Directed Graph
        adj[u].push_back(v);
    }
    
    vector<bool> visited(V,false);
    
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> pathVisited(V,false);
            if(detectCycle(adj,visited,pathVisited,i))return true;
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