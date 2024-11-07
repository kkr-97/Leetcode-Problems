class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int prevAnd = candidates[0];
        int ans = 0;
        for(int i = 0; i < 24; i++){
            int curCnt = 0;
            for(int num : candidates){
                int curBit = (num >> i) & 1;
                if(curBit == 1){
                    curCnt++;
                }
            }
            ans = max(ans, curCnt);
        }
    return ans;
    }
};