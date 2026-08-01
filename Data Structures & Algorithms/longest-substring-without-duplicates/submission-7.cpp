class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> d;
        int bleft = 0, bright = 0, cleft = 0, cright = 0;
        if (s == "")
            return 0;

        for(int i = 0; i < s.size(); i++){
            // if (s[i] == ' ')
            //     d[' ']++;
            if (!d.count(s[i])){
                d[s[i]]++;
                cright=i;
            } else {
                while(d.count(s[i])){
                    d.erase(s[cleft++]);
                }
                d[s[i]]++;
                cright=i;
            }
            if(cright - cleft > bright - bleft) {
                bright = cright, bleft = cleft;
            }
        }
        return bright - bleft + 1;
    }
};
