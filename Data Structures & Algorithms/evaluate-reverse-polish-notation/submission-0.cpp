class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    int res = 0;
    stack<int> s;

    for(string c : tokens){
        if (c == "+"){
            for(int i = 0; i < 1; i++){
                int el1 = s.top(); s.pop();
                int el2 = s.top(); s.pop();
                s.push(el1 + el2);
            }
        } else if (c == "-") {
            for(int i = 0; i < 1; i++){
                int el1 = s.top(); s.pop();
                int el2 = s.top(); s.pop();
                s.push(-el1 + el2);
            }
        } else if (c == "*"){
            for(int i = 0; i < 1; i++){
                int el1 = s.top(); s.pop();
                int el2 = s.top(); s.pop();
                s.push(el1 * el2);
            }
        } else if (c == "/"){
            for(int i = 0; i < 1; i++){
                int el1 = s.top(); s.pop();
                int el2 = s.top(); s.pop();
                s.push(el2/el1);
            }
        } else {
            s.push(stoi(c));
        }
    }
    return s.top();

    }
};
