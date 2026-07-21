#include <iostream>

class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), 
        [](unsigned char c){return tolower(c); });
        size_t begin = 0;
        size_t end = s.size() - 1;

        bool broken = false;
        while (begin < end){
        while (!std::isalpha(s[begin]) && !isdigit(s[begin])) {
            begin++;
            if (begin >= end) return true;
        }
        while (!std::isalpha(s[end]) && !isdigit(s[begin])){ 
            end--;
            if (begin >= end) return true;
        }
        
        if (s[begin++] != s[end--]){
            broken = true;
            break;
        }
        }

        if (broken) return false; else return true;
    }
};
