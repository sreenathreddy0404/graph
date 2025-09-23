#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<bool> visited(V,false);
       
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        int cost = 0;
        while(!pq.empty()){
            auto it = pq.top();pq.pop();
            int w = it.first;
            int u = it.second;
            if(visited[u])continue;
            visited[u] = true;
            cost += w;
            for(auto node:adj[u]){
                int v = node.first;
                int d = node.second;
                if(!visited[v]){
                    pq.push({d,v});
                }
            }
        }
        
        
        return cost;
    }
};

//T.C = O(ElogV)
//S.C = O(V + E)