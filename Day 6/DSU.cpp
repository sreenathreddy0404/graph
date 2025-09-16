#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent;

public:
    // constructor
    DisjointSet(int n) {
        parent.resize(n+1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;  // initially, each node is its own parent
        }
    }

    // Find (no path compression)
    int findParent(int node) {
        if (node == parent[node]) return node;
        return findParent(parent[node]);
    }

    // Union (simple version)
    void unionSet(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu != pv) {
            parent[pv] = pu;  // attach pv's set to pu
        }
    }
};

int main() {
    DisjointSet ds(7);

    ds.unionSet(1, 2);
    ds.unionSet(2, 3);
    ds.unionSet(4, 5);
    ds.unionSet(6, 7);
    ds.unionSet(5, 6);

    // check if 3 and 7 are in same set
    if (ds.findParent(3) == ds.findParent(7)) {
        cout << "Same Set\n";
    } else {
        cout << "Different Set\n";
    }

    ds.unionSet(3, 7);

    if (ds.findParent(3) == ds.findParent(7)) {
        cout << "Same Set\n";
    } else {
        cout << "Different Set\n";
    }
}
