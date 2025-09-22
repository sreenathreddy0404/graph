#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src, int dest) {
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1); // to store path
    dist[src] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});

    while(!pq.empty()) {
        auto it = pq.top();
        int d = it.first;
        int u = it.second;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if(d + w < dist[v]) {
                dist[v] = d + w;
                parent[v] = u;   // update parent
                pq.push({dist[v], v});
            }
        }
    }

    // if no path exists
    if(dist[dest] == INT_MAX) return {-1};

    // reconstruct path from dest back to src
    vector<int> path;
    for(int v = dest; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int V = 5;
    vector<vector<pair<int,int>>> adj(V);

    // undirected graph edges
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({2, 4});
    adj[2].push_back({0, 4});

    adj[1].push_back({2, 1});
    adj[2].push_back({1, 1});

    adj[1].push_back({3, 7});
    adj[3].push_back({1, 7});

    adj[2].push_back({4, 3});
    adj[4].push_back({2, 3});

    adj[3].push_back({4, 1});
    adj[4].push_back({3, 1});

    int src = 0, dest = 4;
    vector<int> path = dijkstra(V, adj, src, dest);

    if(path.size() == 1 && path[0] == -1) {
        cout << "No path exists\n";
    } else {
        cout << "Shortest path from " << src << " to " << dest << ": ";
        for(int node : path) cout << node << " ";
        cout << "\n";
    }
}
