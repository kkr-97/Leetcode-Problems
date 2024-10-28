class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<float> s;
        for(int num : nums){
            s.insert((float)num);
        }
        int ans = -1;
        for(int n : s){
            float cur = n;
            int len = 0;

            while(s.find(cur) != s.end()){
                len++;
                // s.erase(cur);
                cur = pow(cur, 0.5);
            }
            ans = max(len, ans);
        }
        return ans == 1 ? -1 : ans;
    }
};