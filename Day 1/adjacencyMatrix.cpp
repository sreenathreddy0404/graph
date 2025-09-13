#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    // Create V+1 x V+1 matrix (1-indexed)
    // Create  V x V matrix (0-indexed)
    vector<vector<int>> adj(V, vector<int>(V, 0));

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        // For undirected graph
        adj[u][v] = 1;
        adj[v][u] = 1;

        //If directed,"adj[v][u] = 1"
    }

    // Printing the adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
