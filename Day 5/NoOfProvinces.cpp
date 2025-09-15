#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> &adj,int source,vector<bool> &visited){
        visited[source] = true;
        for(auto neighbour:adj[source]){
            if(!visited[neighbour]){
                dfs(adj,neighbour,visited);
            }
        }
    }
    int NoOfProvinces(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adj(V);
        
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }

        int count = 0;
        vector<bool> visited(V,false);

        for(int i=0;i<V;i++){
            if(!visited[i]){
                count++;
                dfs(adj,i,visited);
            }
        }
        
        return count;
    }
};