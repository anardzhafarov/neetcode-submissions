class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowestPrice = prices[0];
        int priceDiff = 0;
        for(int i = 1; i < prices.size(); i++){
            int currDiff = prices[i] - lowestPrice;
            if (currDiff > priceDiff) 
                priceDiff = currDiff;
            else if (lowestPrice > prices[i])
                lowestPrice = prices[i];
        }
        return priceDiff;
    }
};
