#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(vector<int> adj[],vector<bool> &visited,int src){
        visited[src] = true;
        for(auto node:adj[src]){
            if(!visited[node]){
                dfs(adj,visited,node);
            }
        }
    }
    int isEulerCircuit(int V, vector<int> adj[]) {
        //1. check all non zero degree vertices are connected if not return 0;
        //2. if all vertices degree is even(eular circuit) then return 2.
        //3. else if oddDegree vertices is equal to 2(semi eludian) then return 1;
        //4. else return 0; (euler path not exits.)
        
        vector<int> indeg(V,0);
        int oddDegree = 0;
        for(int i=0;i<V;i++){
            indeg[i] = adj[i].size();
            if(indeg[i]%2 !=0 )oddDegree++;
        }
        
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(indeg[i] != 0){
                dfs(adj,visited,i);
                break;
            }
        }
        
        for(int i=0;i<V;i++){
            if(!visited[i] && indeg[i] != 0)return 0;
        }
        
        
        if(oddDegree == 0)return 2;
        if(oddDegree == 2)return 1;
        return 0;
    }
};