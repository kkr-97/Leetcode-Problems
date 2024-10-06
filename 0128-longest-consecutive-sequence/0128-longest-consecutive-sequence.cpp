class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> s;
        int res = 1;
        int cnt = 0;
        for(int num : nums){
            s.insert(num);
        }
        for(int num : nums){
            if(s.find(num-1) == s.end()){
                cnt = 1;
                int cur = num;
                while(s.find(cur+1) != s.end()){
                    cnt++;
                    cur++;
                }
            }
            res = max(cnt, res);
        }
        return res;
    }
};