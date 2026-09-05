class Solution {
public:
    void flood(vector<vector<int>> &heights, vector<vector<bool>> &visited){
        queue<pair<int, int>> q;
        int n = heights.size();
        int m = heights[0].size();
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visited[i][j])
                    q.push({i, j});
            }
        }

        while(!q.empty()){
            pair<int, int> front = q.front();
            q.pop();
            int x = front.first;
            int y = front.second;
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                if(heights[nx][ny] < heights[x][y] || visited[nx][ny])
                    continue;
                
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> hasPacific(n, vector<bool>(m, false));
        vector<vector<bool>> hasAtlantic(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++){
            hasPacific[i][0] = true;
            hasAtlantic[i][m - 1] = true;
        }
        for(int j = 0; j < m; j++){
            hasPacific[0][j] = true;
            hasAtlantic[n - 1][j] = true;
        }

        flood(heights, hasAtlantic);
        flood(heights, hasPacific);
        
        vector<vector<int>> result;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(hasAtlantic[i][j] && hasPacific[i][j])
                    result.push_back({i, j});
            }
        }

        return result;
    }
};
