#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent;
    vector<int> height;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        height.resize(n+1,1);

        for(int i=0;i<n+1;i++)parent[i] = i;
    }

    int find(int u){
        if(parent[u] == u)return u;

        return parent[u] = find(parent[u]);
    }

    void Union(int u,int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv)return;

        if(height[pu] < height[pv]){
            parent[pu] = pv;
        }else if(height[pv] < height[pu]){
            parent[pv] = pu;
        }else{
            parent[pu] = pv;
            height[pv]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int E = connections.size();
        if(n > E+1) return -1;

        DisjointSet ds(n);
        for(auto &c:connections){
            ds.Union(c[0],c[1]);
        }

        int count = -1;
        for(int i=0;i<n;i++){
            if(i == ds.find(i))count++;
        }
        return count;
    }
};