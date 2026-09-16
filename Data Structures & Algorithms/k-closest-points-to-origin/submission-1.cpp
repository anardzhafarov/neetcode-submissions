class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<long long, vector<vector<int>>> m;
        for(const auto& i : points){
            long long distance = static_cast<long long>(i[0]) * i[0] + static_cast<long long>(i[1]) * i[1];
            if(!m.count(distance)){
                m.insert({distance, {i}});
            } else {
                m[distance].push_back(i);
            }
        }
        vector<vector<int>> res;
        for(auto& [d, vv] : m){
            while(!vv.empty() && k > 0){
                res.push_back(vv.back());
                vv.pop_back();
                k--;
            }
        }
        return res;
    }
};
