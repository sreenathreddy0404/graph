#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        int m = times.size();
        for(int i=0;i<m;i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v,w});
        }

        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});

        while(!pq.empty()){
            auto it = pq.top();pq.pop();
            int d = it.first;
            int u = it.second;

            for(auto node:adj[u]){
                int v = node.first;
                int w = node.second;

                if(d+w < dist[v]){
                    dist[v] = d+w;
                    pq.push({dist[v],v});
                }
            }
        }

        int ans = 0;
        for(int i=1;i<=n;i++){
            if(dist[i] == INT_MAX)return -1;
            ans = max(ans,dist[i]);
        }

        return ans;
    }
};