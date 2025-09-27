#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int,int> bfs(unordered_map<int,vector<int>> &adj,int src){
         int V = adj.size();
        vector<int> visited(V,false);
        queue<int> q;
        q.push(src);//random node;
        visited[src] = true;
        int A = src;//farthest node;
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int node = q.front();
                q.pop();
                for(auto neigh:adj[node]){
                    if(!visited[neigh]){
                        visited[neigh] = true;
                        q.push(neigh);
                        A = neigh;//update farthest
                    }
                }
            }
            level++;
        }
        return {A,level-1};
    }
    int diameter(vector<vector<int>>& edges) {
        if(edges.size() == 0)return 0;
        unordered_map<int,vector<int>> adj;
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        auto it = bfs(adj,0);
        int endpoint = it.first;
        int dist1 = it.second;

        auto it1 = bfs(adj,endpoint);
        int otherEndPoint = it1.first;
        int distance = it1.second;
        return distance;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int diameterOfA = diameter(edges1);
        int diameterOfB = diameter(edges2);
        cout<<diameterOfA<<" "<<diameterOfB;
        
        int combined = ((diameterOfA+1)/2 + (diameterOfB+1)/2)+1;
        return max({diameterOfA,diameterOfB,combined});
    }
};