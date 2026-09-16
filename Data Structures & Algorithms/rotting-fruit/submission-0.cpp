class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        int res = 0, fresh = 0;
        queue<pair<int, int>> rottens;

        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(grid[row][col] == 2){
                    rottens.push({row, col});
                } else if (grid[row][col] == 1)
                    fresh++;
            }
        }

        int len = rottens.size();
        while(!rottens.empty()){
            res = len == 0 ? res + 1 : res;
            len = len == 0 ? rottens.size() : len;
    
            auto [row, col] = rottens.front();
            rottens.pop(); len--;

            int left = col - 1 >= 0 ? col - 1 : -1;
            int right = col + 1 < cols ? col + 1 : -1;
            int up = row - 1 >= 0 ? row - 1 : -1;
            int down = row + 1 < rows ? row + 1 : -1;

            if(right != -1 && grid[row][right] == 1){
                fresh--;
                grid[row][right] = 2;
                rottens.push({row, right});
            }
            if(left != -1 && grid[row][left] == 1){
                fresh--;
                grid[row][left] = 2;
                rottens.push({row, left});
            }
            if(up != -1 && grid[up][col] == 1){
                fresh--;
                grid[up][col] = 2;
                rottens.push({up, col});
            }
            if(down != -1 && grid[down][col] == 1){
                fresh--;
                grid[down][col] = 2;
                rottens.push({down, col});
            }
        }
        if(fresh == 0)
            return res;
        else
            return -1;
    }
};
