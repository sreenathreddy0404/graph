#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1)return -1;
        else if(n==1)return 1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            level++;
            while(size--){
                auto it = q.front();q.pop();
                int i = it.first;
                int j = it.second;

                for(int p=-1;p<=1;p++){
                    for(int r = -1;r<=1;r++){
                        if(p==0 && r==0)continue;
                        int ni = i+p;
                        int nj = j+r;
                        if(ni<0||nj<0||ni==n||nj==n||grid[ni][nj] == 1)continue;
                        if(ni == n-1 && nj == n-1)return level+1;
                        grid[ni][nj] = 1;
                        q.push({ni,nj});
                    }
                }
            }
            
        }
        return -1;
    }
};