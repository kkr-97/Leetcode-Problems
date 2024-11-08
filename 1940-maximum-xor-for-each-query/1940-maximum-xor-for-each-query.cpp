class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int l = nums.size();
        vector<int> xors(l);
        xors[0] = nums[0];
        for(int i = 1; i < l; i++){
            xors[i] = xors[i-1] ^ nums[i];
        }
        int k = pow(2, maximumBit) - 1;
        vector<int> ans(l);

        int last = l;
        for(int i = 0; i < l; i++){
            if(xors[last-1] == k){
                ans[i] = 0;
            }
            else{
                ans[i] = xors[last-1] ^ k;
            }
            last--;
        }
        return ans;
    }
};