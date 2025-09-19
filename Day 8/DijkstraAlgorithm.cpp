#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Min-heap: (distance, node)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});

    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if(d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

vector<int> dijkstraUsingSet(int V, vector<vector<pair<int,int>>> &adj, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    set<pair<int,int>> s; // (distance, node)
    s.insert({0, src});

    while(!s.empty()) {
        auto it = *s.begin();
        int d = it.first;
        int u = it.second;
        s.erase(s.begin());

        for(auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if(d + w < dist[v]) {
                // remove old entry if exists
                if(dist[v] != INT_MAX) {
                    s.erase({dist[v], v});
                }
                dist[v] = d + w;
                s.insert({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int V = 5;
    vector<vector<pair<int,int>>> adj(V);

    // Example graph (u, v, w)
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});

    vector<int> dist = dijkstra(V, adj, 0);

    cout << "Shortest distances from source 0:\n";
    for(int i=0;i<V;i++) {
        cout << "Node " << i << " : " << dist[i] << "\n";
    }
}
