#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int diameter(vector<vector<int>>& adj) {
        //diameter is the longest shortest path in a graph.

        //start from random node find the farthest node from it. call it A. It is one of the end of diameter always.
        //start from A find the farthest distance. It is our diameter.
        //because A is one end of diameter. farthest distance from one end is always our diameter.

        int V = adj.size();
        vector<int> visited(V,false);
        queue<int> q;
        q.push(0);//random node;
        visited[0] = true;
        int A = 0;//farthest node;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int node = q.front();
                q.pop();
                for(auto neigh:adj[node]){
                    if(!visited[neigh]){
                        visited[neigh] = true;
                        q.push(neigh);
                        A = neigh;
                    }
                }
            }
        }

        q.push(A);
        int level = 0;
        for(int i=0;i<V;i++){
            visited[i] = false;
        }

        while(!q.empty()){
            int size = q.size();
            while(size--){
                int node = q.front();q.pop();
                for(auto neigh:adj[node]){
                    if(!visited[neigh]){
                        visited[neigh] = true;
                        q.push(neigh);
                    }
                }
            }
            level++;
        }
        return level;
    }
};