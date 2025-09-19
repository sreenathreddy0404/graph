//leetcode no 990. best use of union find.

#include<bits/stdc++.h>
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
    bool equationsPossible(vector<string>& equations) {
        DisjointSet ds(26);
        
        for(auto s:equations){
            if(s[1] == '=')ds.Union(s[0]-'a',s[3]-'a');
        }

        for(auto s:equations){
            if(s[1] == '!' && ds.find(s[0]-'a') == ds.find(s[3]-'a')) return false;
        }

        return true;
    }
};