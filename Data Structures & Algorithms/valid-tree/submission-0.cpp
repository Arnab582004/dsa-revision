class Solution {
    bool dfs(int n,int node, int parent, vector<int>& visited, vector<vector<int>>& adj, int& visitedCount){
        visited[node]=1;
        visitedCount++;
        for(auto adjacentnode: adj[node]){
            if(!visited[adjacentnode]){
                //visited[adjacentnode]=1;
                if(!dfs(n,adjacentnode,node,visited,adj,visitedCount)){
                    return false;
            }
            }
            else if(adjacentnode!=parent){
                return false;
            }
            //else if(visitedCount!=n)return false;
        }
        return true;
        
    }
    
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n==0)return false;
        vector<int>visited(n,0);
        vector<vector<int>>adj(n);
        int visitedCount=0;
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        if(!dfs(n,0,-1,visited,adj,visitedCount)){
            return false;
        }
        return visitedCount==n;
    }
};
