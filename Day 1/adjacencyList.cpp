#include <bits/stdc++.h>
using namespace std;

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

        // 👉 If directed, comment out the adj[v].push_back(u) line
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

    return 0;
}
