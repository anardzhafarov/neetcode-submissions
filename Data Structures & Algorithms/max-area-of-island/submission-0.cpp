class Solution {
public:
    void walk(vector<vector<int>>& grid, pair<int, int> i, int& curr){
        curr++;
        grid[i.first][i.second] = 0;
        int rows = grid.size(); int cols = grid[0].size();
        int up = i.first - 1 >= 0 ? i.first - 1 : -1;
        int down  = i.first + 1 < rows ? i.first + 1 : -1;
        int left  = i.second - 1 >= 0 ? i.second - 1 : -1;
        int right  = i.second + 1 < cols ? i.second + 1 : -1;

        if(up != -1 && grid[up][i.second] == 1)
            walk(grid, {up, i.second}, curr);
        if(down != -1 && grid[down][i.second] == 1)
            walk(grid, {down, i.second}, curr);
        if(left != -1 && grid[i.first][left] == 1)
            walk(grid, {i.first, left}, curr);
        if(right != -1 && grid[i.first][right] == 1)
            walk(grid, {i.first, right}, curr);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size(); int cols = grid[0].size();
        int best = 0;
        int curr = 0;

        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(grid[row][col] == 1){
                    walk(grid, {row, col}, curr);
                }
                best = curr > best ? curr : best;
                curr = 0;
            }
        }
        return best;
    }
};
