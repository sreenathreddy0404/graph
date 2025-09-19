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
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);

        for(auto e:edges){
            ds.Union(e[0],e[1]);
        }

        unordered_map<int,int> hashmap;
        for(int i=0;i<n;i++){
            hashmap[ds.find(i)]++;
        }

        long long rem = n;
        long long ans = 0;
        for(auto k:hashmap){
            rem -= k.second;
            ans += rem * k.second;
        }

        return ans;
    }
};