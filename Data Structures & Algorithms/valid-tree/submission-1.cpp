class Solution {
public:
    bool dfs(int node, int par, vector<vector<int>>& adj, vector<bool>& visited){
        if(visited[node])
            return false;
        
        bool valid = true;
        visited[node] = true;
        for(int neigh: adj[node]){
            if(neigh == par)
                continue;
            
            valid &= dfs(neigh, node, adj, visited);
        }
        return valid;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n);
        for(int i = 0; i < edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bool valid = true;
        int count = 0;
        for(int i = 0; i < n ; i++){
            if(visited[i])
                continue;
             valid &= dfs(i, -1, adj, visited);
             count++;
        }
        return count == 1 && valid;
    }
};
