#include <bits/stdc++.h>
using namespace std;

void dfs1(int node, vector<int> adj[], vector<int> &vis, stack<int> &st) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) dfs1(it, adj, vis, st);
    }
    st.push(node);
}

void dfs2(int node, vector<int> revAdj[], vector<int> &vis) {
    vis[node] = 1;
    cout << node << " ";  // Print component
    for (auto it : revAdj[node]) {
        if (!vis[it]) dfs2(it, revAdj, vis);
    }
}

void kosaraju(int V, vector<int> adj[]) {
    stack<int> st;
    vector<int> vis(V, 0);

    // Step 1: DFS by finish time
    for (int i = 0; i < V; i++) {
        if (!vis[i]) dfs1(i, adj, vis, st);
    }

    // Step 2: Reverse Graph
    vector<int> revAdj[V];
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            revAdj[it].push_back(i);
        }
    }

    // Step 3: DFS on reversed graph
    fill(vis.begin(), vis.end(), 0);
    while (!st.empty()) {
        int node = st.top(); st.pop();
        if (!vis[node]) {
            dfs2(node, revAdj, vis);
            cout << endl;  // One SCC complete
        }
    }
}

int main() {
    int V = 5;
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[1].push_back(4);
    adj[4].push_back(0);

    kosaraju(V, adj);
}
