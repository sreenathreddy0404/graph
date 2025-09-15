#include<bits/stdc++.h>
using namespace std;


vector<int> kahn(vector<vector<int>> &edges,int V){
    vector<vector<int>> adj(V);
    vector<int> indegree(V,0);
        
    //topoSort Works only on Directed ACyclic Graph (DAG)
    for(auto edge:edges){
        int u = edge[0];
        int v = edge[1];
        
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    //push into queue whose indegree is equal to zero
    for(int i=0;i<V;i++){
        if(indegree[i] == 0)q.push(i);
    }

    vector<int> ans;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto neigh:adj[node]){
            if(indegree[neigh] != 0){
                indegree[neigh]--;
                if(indegree[neigh] == 0)q.push(neigh);
            }
        }
    }

    return ans;
}