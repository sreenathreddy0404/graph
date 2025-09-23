#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &grid) {
        int V = grid.size();
        for(int via = 0; via<V;via++){
            for(int u=0;u<V;u++){
                for(int v=0;v<V;v++){
                    if(grid[u][via] == 1e8 || grid[via][v] == 1e8)continue;
                    grid[u][v] = min(grid[u][v],grid[u][via]+grid[via][v]);
                }
            }
        }


        for(int i=0;i<V;i++){
            if(grid[i][i] < 0)return;//if diagonals have negative weights then there is negative cycle;
        }
    }
};

//T.C = O(V^3)
//S.C = O(1)