#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
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
    int removeStones(vector<vector<int>>& stones) { 
        n = stones.size();
        vector<int> parent(n);
        for(int i=0;i<n;i++)parent[i] = i;
        
        for(int k=0;k<n;k++){
            for(int l = k+1;l<n;l++){
                if(stones[k][0] == stones[l][0] || stones[k][1] == stones[l][1])
                    Union(parent,k,l);
            }
        }

        int groups = 0;
        for(int i=0;i<n;i++){
            if(parent[i] == i){
                groups++;
            }
        }

        return n-groups;
    }
};


//   0   1   2   3   4
//0      s   s   s
//1      s
//2                  s
//3
//4               s