// You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

// The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

// Solution: Just count the number of adjacent 1s' for a {1} in the matrix and add 4-(count of adjacent 1s') to the perimeter,start by calling a dfs function when encountered the first {1}

class Solution {
public:
    int ones(int i,int j,vector<vector<int>>& grid){
        int cnt=0;
        if(i-1>=0 && grid[i-1][j]==1){
            cnt++;
        }
        if(i+1<grid.size() && grid[i+1][j]==1){
            cnt++;
        }
        if(j-1>=0 && grid[i][j-1]==1){
            cnt++;
        }
        if(j+1<grid[0].size() && grid[i][j+1]==1){
            cnt++;
        }
        return (4-cnt);
    }

    void dfs(int i,int j,vector<vector<int>>& grid,map<pair<int,int>,int> &mp,int &cnt){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0) return ;
        if(i>=n || j>=m ) return ;
        if(grid[i][j]==0) return;
        if(mp[{i,j}]>0) return ;

        mp[{i,j}]=1;
        cnt+=ones(i,j,grid);
        dfs(i-1,j,grid,mp,cnt);
        dfs(i+1,j,grid,mp,cnt);
        dfs(i,j-1,grid,mp,cnt);
        dfs(i,j+1,grid,mp,cnt);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        map<pair<int,int>,int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mp[{i,j}]==0){
                    dfs(i,j,grid,mp,cnt);
                }
            }
        }
        return cnt;
    }
};