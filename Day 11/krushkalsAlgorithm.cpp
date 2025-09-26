#include<bits/stdc++.h>
using namespace std;

class Solution {
    int find(vector<int> &parent,int u){
        if(parent[u] == u)return u;
        return parent[u] = find(parent,parent[u]);
    }
    
    void Union(vector<int> &parent,int u,int v){
        int pu = find(parent,u);
        int pv = find(parent,v);
        if(pu == pv)return;
        parent[pu] = pv;
    }
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<int>parent(V);
        for(int i=0;i<V;i++)parent[i] = i;
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        
        for(auto edge:edges){
            pq.push({edge[2],edge[0],edge[1]});
        }
        
        int cost = 0;
        
        while(!pq.empty()){
            auto it = pq.top();pq.pop();
            int w = it[0];
            int u = it[1];
            int v = it[2];
            if(find(parent,u) == find(parent,v))continue;
            cost += w;
            Union(parent,u,v);
        }
        
        return cost;
    }
};