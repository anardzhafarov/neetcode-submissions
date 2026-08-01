class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) 
            return false;
        else if (s1.size() == s2.size()) {
            string s1s = s1;
            sort(s1s.begin(), s1s.end());
            string s2s = s2;
            sort(s2s.begin(), s2s.end());
            return s1s == s2s;
        } 
        else {
            string s1s = s1;
            sort(s1s.begin(), s1s.end());
            for(int i = 0; i < s2.size(); i++){
                string curr_s = s2.substr(i, s1.size());
                sort(curr_s.begin(), curr_s.end());
                if(curr_s == s1s) 
                    return true;
            }
        }
        return false;
    }
};