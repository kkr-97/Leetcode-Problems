class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < 32; i++){
            int cntBits = 0;
            for(int num : nums){
                if(1 & (num >> i)){
                    cntBits++;
                    cntBits %= 3;
                }
            }
            if(cntBits > 0){
                res = res | (1 << i);
            }
        }
        return res;
    }
};