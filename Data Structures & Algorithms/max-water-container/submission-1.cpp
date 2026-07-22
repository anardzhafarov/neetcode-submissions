class Solution {
public:
    int maxArea(vector<int>& heights) {
        int bestRes{};

        for(int i = 0; i < heights.size() - 1; i++){
            for(int j = 0; j < heights.size(); j++){
                int c = min(heights[i], heights[j]) * (j-i);
                if (c > bestRes)
                    bestRes = c;
            }
        }
        return bestRes;
    }
};
