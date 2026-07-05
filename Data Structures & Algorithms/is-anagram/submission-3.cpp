class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> sl{};
        unordered_map<char, int> tl{};

        for(int i = 0; i < s.size(); i++){
            sl[s[i]]++;
            tl[t[i]]++;
        }

        return sl == tl;
    }
};
