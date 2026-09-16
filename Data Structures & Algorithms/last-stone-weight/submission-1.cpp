class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(stones.begin(), stones.end());
        while(q.size() > 1){
            int s1 = q.top();
            q.pop();
            int s2 = q.top();
            q.pop();
            if(s1 > s2){
                q.push(s1-s2);
            } else if (s2 > s1){
                q.push(s2-s1);
            }
        }
        if(q.empty())
            return 0;
        else
            return q.top();
    }
};
