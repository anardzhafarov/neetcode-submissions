class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> strings = strs;
        for(string& s : strings){
            sort(s.begin(), s.end());
        }

        unordered_map<string, vector<string>> r {};
        for(int i = 0; i < strs.size(); i++){
            r[strings[i]].push_back(strs[i]);
        }

        vector<vector<string>> res {};

        for(const auto& p : r){
            res.push_back(p.second);
        }

        return res;
    }
};
