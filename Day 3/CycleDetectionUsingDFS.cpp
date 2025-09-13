#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &adj,int source,vector<bool> &visited,int parent){
    visited[source] = true;
    for(auto neighbour:adj[source]){
        if(!visited[neighbour]){
            if(dfs(adj,neighbour,visited,source))return true;
        }else if(parent != neighbour) return true;
    }
    return false;
}

bool cycle(vector<vector<int>> &adj,int V){
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(dfs(adj,i,visited,-1))return true;
        }
    }
    return false;
}

int main() {
    int V = 5, E = 5;
    vector<vector<int>> adj(V);
    vector<pair<int,int>> edges = {{0,1},{1,2},{1,4},{2,3},{3,4}};
    for (int i = 0; i < E; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < V; i++) {
        cout << i << " -> ";
        for (auto x : adj[i]) cout << x << " ";
        cout << endl;
    }
    if(cycle(adj,V)) cout<<"Cycle is detected";
    else cout<<"No cycle detected";
    return 0;
}
