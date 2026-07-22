class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;

    for(int i = 0; i + 2 < nums.size();i++){
        if(i > 0)
            if (nums[i] == nums[i-1])
                continue;
        
        int curr_num = nums[i];
        // TwoSum 2
        int p1 = i+1;
        int p2 = nums.size() - 1;
        while(p1 < p2){
            if(nums[p1] + nums[p2] > -curr_num){
                p2--;
                while (p2 > p1 && p2 > p1 && nums[p2+1] == nums[p2])
                    p2--;
            } else if (nums[p1] + nums[p2] < -curr_num){
                p1++;
                while(p1 < p2 && nums[p1-1] == nums[p1])
                    p1++;
            } else {
                res.push_back(vector<int>{nums[i], nums[p1], nums[p2]});
                p1++;
                while(p1 < p2 && nums[p1-1] == nums[p1])
                    p1++;
                p2--;
                while (p2 > p1 && nums[p2+1] == nums[p2])
                    p2--;
            }
        }
        
    }
    return res;
    }
};
