class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> m; // req, index_orig

        for(auto i = 0; i < numbers.size(); i++){
            if (!m.count(numbers[i])) {
                m.insert({target - numbers[i], i});
            } else {
                return vector<int> {m[numbers[i]] + 1, i + 1};
            }
        }
        return {};
    }
};
