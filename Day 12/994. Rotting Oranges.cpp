#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;
        int fresh = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1)fresh++;
                if(grid[i][j] == 2)q.push({i,j});
            }
        }

        int time = 0;
        vector<int> row = {-1,0,1,0};
        vector<int> col = {0,1,0,-1};
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto it = q.front();q.pop();
                int i = it.first;
                int j = it.second;

                for(int k=0;k<4;k++){
                    int ni = i+row[k];
                    int nj = j+col[k];
                    if(ni<0 || nj<0 || ni>=n || nj>=m || grid[ni][nj]!=1)continue;
                    fresh--;
                    grid[ni][nj] = 2;
                    q.push({ni,nj});
                }
            }
            if(!q.empty())time++;
        }
        
        if(fresh == 0)return time;
        return -1;
    }
};