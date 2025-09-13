#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj,int source,vector<bool> &visited){
    visited[source] = true;
    cout<<source<<" ";
    for(auto neighbour:adj[source]){
        if(!visited[neighbour])dfs(adj,neighbour,visited);
    }
}

void iterativeDFS(vector<vector<int>> &adj,int source,vector<bool> &visited){
    stack<int> st;
    st.push(source);
    int V = adj.size();
    while(!st.empty()){
        int src = st.top();
        st.pop();
        if(!visited[src]){
            visited[src] = true;
            cout<<src<<" ";
            for(int i=adj[src].size()-1;i>=0;i--){
                if(!visited[adj[src][i]]){
                    st.push(adj[src][i]);
                }
            }
        }
        
    }
}

void DFS(vector<vector<int>> &adj,int source,int V){
    vector<bool>visited(V,false);
    for(auto neighbour:adj[source]){
        if(!visited[neighbour])dfs(adj,neighbour,visited);
    }
}
int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    // Create adjacency list
    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        // For undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Printing the adjacency list
    cout << "\nAdjacency List:\n";
    for (int i = 1; i <= V; i++) {
        cout << i << " -> ";
        for (auto x : adj[i]) {
            cout << x << " ";
        }
        cout << endl;
    }

    DFS(adj,0,V);

    return 0;
}
