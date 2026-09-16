class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int target_i = nums.size() - k;
        int pivot = nums.size() - 1;
        int left = 0, right = nums.size() - 1;
        do {
            pivot = right;
            int i = left, j = left;
            while(j < pivot){
                if(nums[j] < nums[pivot]){
                    int temp = nums[i];
                    nums[i++] = nums[j];
                    nums[j++] = temp;
                } else if (nums[j] >= nums[pivot])
                    j++;
            }
            int temp = nums[i];
            nums[i] = nums[pivot];
            nums[pivot] = temp;
            pivot = i;
            if(pivot > target_i){
                right = pivot - 1;
            } else if (pivot < target_i){
                left = pivot + 1;
                // pivot = right;
            }
        } while(pivot != target_i);
        // cout << pivot;
        // for(int i : nums)
        //     cout << i << " ";
        return nums[pivot];
    }
};
