class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        queue<pair<int, int>> q;
        int countFresh = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    countFresh++;
            }
        }
        if(countFresh == 0) return 0;
        int timePassed = 0;
        while(!q.empty() && countFresh > 0){
            int sz = q.size();
            for(int k = 0; k < sz; k++){
                pair<int, int> top = q.front();
                q.pop();
                int x = top.first;
                int y = top.second;
                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx < 0 || nx >=n || ny < 0 || ny >=m)
                        continue;
                    if(grid[nx][ny] == 0 || grid[nx][ny] == 2)
                        continue;
                    
                    countFresh--;
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
            timePassed++;
        }
        return countFresh == 0 ? timePassed : -1; 
    }
};
