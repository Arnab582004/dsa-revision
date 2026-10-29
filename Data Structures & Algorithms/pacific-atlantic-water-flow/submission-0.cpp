class Solution {
    void dfspacific(int row , int col , int m , int n , int delrow[] , int delcol[] , vector<vector<bool>> &pacific ,vector<vector<int>>&heights){
        pacific[row][col]=true;
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n  && pacific[nrow][ncol]==false && heights[nrow][ncol]>=heights[row][col]){
                dfspacific(nrow,ncol,m,n,delrow,delcol,pacific,heights);
            }
        }
    }
    void dfsatlantic(int row , int col , int m , int n , int delrow[] , int delcol[] , vector<vector<bool>> &atlantic ,vector<vector<int>>&heights){
        atlantic[row][col]=true;
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n  && atlantic[nrow][ncol]==false && heights[nrow][ncol]>=heights[row][col]){
                dfsatlantic(nrow,ncol,m,n,delrow,delcol,atlantic,heights);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        int delrow[] = {-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<int>>ans;
        //vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dfspacific(0,i,m,n,delrow,delcol,pacific,heights);
        }
        for(int j=0;j<m;j++){
            dfspacific(j,0,m,n,delrow,delcol,pacific,heights);
        }
        for(int i=0;i<n;i++){
             dfsatlantic(m-1,i,m,n,delrow,delcol,atlantic,heights);
        }
        for(int j=0;j<m;j++){
             dfsatlantic(j,n-1,m,n,delrow,delcol,atlantic,heights);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
