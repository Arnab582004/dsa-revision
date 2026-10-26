class Solution {
    void dfs(int row , int col , int m , int n , vector<vector<char>>& grid , vector<vector<int>> & vis , int delrow[] , int delcol[]){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && grid[nrow][ncol] == '1' && vis[nrow][ncol]==0){
                dfs(nrow , ncol , m , n , grid , vis , delrow , delcol);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    dfs(i,j,m,n,grid,vis,delrow,delcol);
                    count++;
                }
                
            }
        }
        return count;
    }
};
