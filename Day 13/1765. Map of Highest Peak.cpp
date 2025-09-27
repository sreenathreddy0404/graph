#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> height(n,vector<int>(m,-1));

        queue<pair<int,int>> q;
        //push all sources into queue.
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j] == 1){
                    height[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        vector<int> row = {-1,0,1,0};
        vector<int> col = {0,1,0,-1};
        //run multisource bfs.
        int level = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto it = q.front();q.pop();
                int i = it.first;
                int j = it.second;
                
                for(int k=0;k<4;k++){
                    int ni = i+row[k];
                    int nj = j+col[k];

                    if(ni<0 || nj<0 ||ni>=n || nj>=m || height[ni][nj] != -1)continue;
                    q.push({ni,nj});
                    height[ni][nj] = level;
                }
            }
            level++;
        }

        return height;
    }
};

//T.C = O(n*m);
//S.C = O(n*m);