#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj,int source,vector<bool> &visited){
    queue<int> q;
    q.push(source);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        visited[node] = true;
        cout<<node<<" ";

        for(auto neighbour:adj[node]){
            if(!visited[neighbour]){
                q.push(neighbour);
            }
        }
    }
}


void BFS(vector<vector<int>> &adj,int source,int V){
    vector<bool>visited(V,false);
    for(auto neighbour:adj[source]){
        if(!visited[neighbour])bfs(adj,neighbour,visited);
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

        //  If directed, adj[v].push_back(u) line
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

    BFS(adj,0,V);

    return 0;
}
