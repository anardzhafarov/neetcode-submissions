class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int lrow = heights.size() - 1; 
    int lcol = heights[0].size() - 1;
    queue<pair<int, int>> q;
    
    for(int row = 0; row <= lrow; row++){
        for(int col = 0; col <= lcol; col++){
            if(row == 0 || row == lrow || col == 0 || col == lcol){
                q.push({row, col});
            }
        }
    }

    vector<vector<bool>> pac(lrow+1, vector<bool>(lcol+1, false));
    vector<vector<bool>> atl(lrow+1, vector<bool>(lcol+1, false));

    for(int col = 0; col <= lcol; col++){
        pac[0][col] = true;
        atl[lrow][col] = true;
    }

    for(int row = 0; row <= lrow; row++){
        pac[row][0] = true;
        atl[row][lcol] = true;
    }

    pac[lrow][0] = true;
    atl[0][lcol] = true; 

    while(!q.empty()){
        auto [row, col] = q.front();
        q.pop();

        int left = col - 1 >= 0 ? col - 1 : -1;
        int right = col + 1 <= lcol ? col + 1 : -1;
        int up = row - 1 >= 0 ? row - 1 : -1;
        int down = row + 1 <= lrow ? row + 1 : -1;

        if(left != -1 && heights[row][left] >= heights[row][col] && (!pac[row][left] || !atl[row][left])){
            if(pac[row][col] && atl[row][col] && !pac[row][left] && !atl[row][left]){
                pac[row][left] = true;
                atl[row][left] = true;
                q.push({row, left});
            } else if(atl[row][col] && !atl[row][left]){
                atl[row][left] = true;
                q.push({row, left});
            } else if(pac[row][col] && !pac[row][left]){
                pac[row][left] = true;
                q.push({row, left});
            }
        }

        if(right != -1 && heights[row][right] >= heights[row][col] && (!pac[row][right] || !atl[row][right])){
            if(pac[row][col] && atl[row][col] && !pac[row][right] && !atl[row][right]){
                pac[row][right] = true;
                atl[row][right] = true;
                q.push({row, right});
            } else if(atl[row][col] && !atl[row][right]){
                atl[row][right] = true;
                q.push({row, right});
            } else if(pac[row][col] && !pac[row][right]){
                pac[row][right] = true;
                q.push({row, right});
            }
        }

        if(up != -1 && heights[up][col] >= heights[row][col] && (!pac[up][col] || !atl[up][col])){
            if(pac[row][col] && atl[row][col] && !pac[up][col] && !atl[up][col]){
                pac[up][col] = true;
                atl[up][col] = true;
                q.push({up, col});
            } else if(atl[row][col] && !atl[up][col]){
                atl[up][col] = true;
                q.push({up, col});
            } else if(pac[row][col] && !pac[up][col]){
                pac[up][col] = true;
                q.push({up, col});
            }
        }

        if(down != -1 && heights[down][col] >= heights[row][col] && (!pac[down][col] || !atl[down][col])){
            if(pac[row][col] && atl[row][col] && !pac[down][col] && !atl[down][col]){
                pac[down][col] = true;
                atl[down][col] = true;
                q.push({down, col});
            } else if(atl[row][col] && !atl[down][col]){
                atl[down][col] = true;
                q.push({down, col});
            } else if(pac[row][col] && !pac[down][col]){
                pac[down][col] = true;
                q.push({down, col});
            }
        }
    }

    vector<vector<int>> res;

    for(int row = 0; row <= lrow; row++){
        for(int col = 0; col <= lcol; col++){
            if(pac[row][col] && atl[row][col])
                res.push_back({row, col});
        }
    }

    return res;
    }
};
