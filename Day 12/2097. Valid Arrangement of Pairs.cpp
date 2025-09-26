#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        //If we carefully observe. This is the Euler's path finding algorithm
        //Given only valid arrangement happen. so it has eulers circuit.

        //Hierholzer's algorithm. for finding euler's path vertices.
        //make adj list.
        //get the startNode.
        //do dfs from startNode;
        //after visting all neighbours push to path.
        //reverse the path.
        //make pairs and store in ans. return ans.

        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> indegree;
        unordered_map<int,int> outdegree;

        int startNode = pairs[0][0];
        int n = pairs.size();
        for(int i=0;i<n;i++){
            int u = pairs[i][0];
            int v = pairs[i][1];
            adj[u].push_back(v);
            indegree[v]++;
            outdegree[u]++;
        }

        for(auto it:adj){
            int node = it.first;
            if(outdegree[node] - indegree[node] == 1){
                startNode = node;
                break;
            }
        }

        stack<int> st;
        st.push(startNode);
        vector<int> path;

        while(!st.empty()){
            int node = st.top();
            if(!adj[node].empty()){
                st.push(adj[node].back());
                adj[node].pop_back();
            }else{
                path.push_back(node);
                st.pop();
            }
        }

        reverse(path.begin(),path.end());
        vector<vector<int>> ans;
        for(int i=0;i<path.size()-1;i++){
            ans.push_back({path[i],path[i+1]});
        }


        return ans;
    }
};