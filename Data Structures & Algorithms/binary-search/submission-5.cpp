class Solution {
public:
    int search(vector<int>& nums, int target) {
        // if (nums.size() == 1){
        //     if (nums[0] == target) return 0;
        //     else return -1; 
        // }
        int left = 0, right = nums.size() - 1;
        while (left + 1 < right){
            int middle = (right + left) / 2;
            if(nums[middle] == target)
                return middle;
            else if (nums[middle] < target) {
                left = middle;
            } else {
                right = middle;
            }
        }
        if (nums[left] == target) return left;
        else if ( nums[right] == target) return right;
        else return -1;
    }
};
