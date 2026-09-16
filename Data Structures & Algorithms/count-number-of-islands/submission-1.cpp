class Solution {
public:
    void walk(vector<vector<char>>& grid, pair<int, int> i){
        grid[i.first][i.second] = '0';
        int rows = grid.size(); int cols = grid[0].size();
        int up = i.first - 1 >= 0 ? i.first - 1 : -1;
        int down  = i.first + 1 < rows ? i.first + 1 : -1;
        int left  = i.second - 1 >= 0 ? i.second - 1 : -1;
        int right  = i.second + 1 < cols ? i.second + 1 : -1;

        if(up != -1 && grid[up][i.second] == '1')
            walk(grid, {up, i.second});
        if(down != -1 && grid[down][i.second] == '1')
            walk(grid, {down, i.second});
        if(left != -1 && grid[i.first][left] == '1')
            walk(grid, {i.first, left});
        if(right != -1 && grid[i.first][right] == '1')
            walk(grid, {i.first, right});
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(); int cols = grid[0].size();
        int res = 0;

        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(grid[row][col] == '1'){
                    res++;
                    walk(grid, {row, col});
                }
            }
        }
        return res;
    }
};
