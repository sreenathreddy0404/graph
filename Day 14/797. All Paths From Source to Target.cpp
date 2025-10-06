#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& graph,int src,vector<int>& temp,vector<vector<int>>& result){
        temp.push_back(src);

        if(src == graph.size()-1){
            result.push_back(temp);
        }

        for(auto u:graph[src]){
            dfs(graph,u,temp,result);
        }

        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp;
        vector<vector<int>> result;

        temp.push_back(0);
        for(auto u:graph[0]){
            dfs(graph,u,temp,result);
        }

        return result;
    }
};