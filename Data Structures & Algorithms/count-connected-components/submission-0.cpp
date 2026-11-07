class Solution {
    void bfs(int node , int n , vector<vector<int>>&adj,vector<int>&visited){
        queue<int>q;
        q.push({node});
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto adjacentnode:adj[node]){
                if(!visited[adjacentnode]){
                    visited[adjacentnode]=1;
                    q.push({adjacentnode});
                }
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>visited(n,0);
        vector<vector<int>>adj(n);
        int count=0;
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bfs(i,n,adj,visited);
                count+=1;
            }
        }
        return count;
        
    }
};
