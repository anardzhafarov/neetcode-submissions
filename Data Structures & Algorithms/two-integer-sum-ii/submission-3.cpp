class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p1 = 0;
        int p2 = numbers.size() - 1;

        while(true){
            int sum = numbers[p1] + numbers[p2];
            if (sum > target) 
                p2--;
            else if (sum < target)
                p1++;
            else 
                return vector<int>{++p1, ++p2};
        }
    }
};
