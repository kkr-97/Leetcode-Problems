class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int ind = (s+s).find(goal);
        return ind >= 0;
    }
};