class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size(); int cols = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(grid[row][col] == 0){
                    q.push({row, col});
                    visited[row][col] = true;
                }
            }
        }

        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            int left = col - 1 >= 0 ? col - 1 : -1;
            int right = col + 1 < cols ? col + 1 : -1;
            int up = row - 1 >= 0 ? row - 1 : -1;
            int down = row + 1 < rows ? row + 1 : -1;

            if(left != -1 && !visited[row][left] && grid[row][left] != -1){
                grid[row][left] = grid[row][col] + 1;
                visited[row][left] = true;
                q.push({row, left});
            }
            if(right != -1 && !visited[row][right] && grid[row][right] != -1){
                grid[row][right] = grid[row][col] + 1;
                visited[row][right] = true;
                q.push({row, right});
            }
            if(up != -1 && !visited[up][col] && grid[up][col] != -1){
                grid[up][col] = grid[row][col] + 1;
                visited[up][col] = true;
                q.push({up, col});
            }
            if(down != -1 && !visited[down][col] && grid[down][col] != -1){
                grid[down][col] = grid[row][col] + 1;
                visited[down][col] = true;
                q.push({down, col});
            }
        }

    }
};
