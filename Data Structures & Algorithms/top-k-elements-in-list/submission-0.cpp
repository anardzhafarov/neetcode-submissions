class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> h{}; // number, frequency 
        for(int n : nums)
            h[n]++;

        vector<pair<int, int>> v(h.begin(), h.end()); // number, frequency
        sort(v.begin(), v.end(), [](const auto& a, const auto& b){
            return a.second < b.second;
        });

        vector<int> res(k);
        for(int i = 0; i < k; i++){
            res[i] = v.back().first; 
            v.pop_back();
        }

        return res;
    }
};
