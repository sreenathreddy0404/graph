#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent;
    vector<int> height;
public:
    DisjointSet(int n) {
        parent.resize(n+1);
        height.resize(n+1,1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }
    int findParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionSet(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv)return;
        if(height[pu]<height[pv]){
            parent[pu] = pv;
        }else if(height[pv]<height[pu]){
            parent[pv] = pu;
        }else{
            parent[pv] = pu;
            height[pv]++;
        }
    }
};

bool detectCycle(int V, vector<pair<int,int>> &edges) {
    DisjointSet ds(V);
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;

        if (ds.findParent(u) == ds.findParent(v)) {
            return true; // cycle found
        }
        ds.unionSet(u, v);
    }
    return false;
}

int main() {
    int V = 5; // vertices
    vector<pair<int,int>> edges = {
        {1,2}, {1,3}, {2,4}, {3,4}
    };

    if (detectCycle(V, edges)) 
        cout << "Cycle Detected\n";
    else 
        cout << "No Cycle\n";
}
