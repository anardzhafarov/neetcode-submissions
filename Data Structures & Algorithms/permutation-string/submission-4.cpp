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
unordered_map<char, int> d1;
        for(char c : s1){
            d1[c]++;
        }
        string curr_s = s2.substr(0, s1.size());
        unordered_map<char, int> d_curr_s;
        for(char c : curr_s){
            d_curr_s[c]++;
        }

        if(d1 == d_curr_s)
            return true;
        for(int i = s1.size(); i < s2.size(); i++){
            // cout << "was " << curr_s;
            curr_s.push_back(s2[i]); 
            if(d_curr_s[curr_s[0]] == 1)
                d_curr_s.erase(curr_s[0]);
            else 
                d_curr_s[curr_s[0]]--;
            curr_s.erase(0, 1); d_curr_s[s2[i]]++;
            // cout << curr_s << '\n';
            // cout << " became " << curr_s;
            if(d1 == d_curr_s) 
                return true;
            }
        }
        return false;
    }
};