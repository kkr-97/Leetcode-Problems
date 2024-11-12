class Solution {
public:
    void setFreqBits(vector<int> &freqBits, int num){
        for(int i = 0; i < 32; i++){
            if((num & (1<<i))){
                freqBits[i]++;
            }
        }
    }

    int countFreqBits(vector<int> &freqBits){
        int cnt = 0;
        for(int i = 0; i < 32; i++){
            if(freqBits[i] > 0){
                cnt = cnt + (1 << i);
            }
        }
        return cnt;
    }

    void unsetFreqBits(vector<int> &freqBits, int num){
        for(int i = 0; i < 32; i++){
            if((num & (1<<i))){
                freqBits[i]--;
            }
        }
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int i = 0, j = 0, l = nums.size();
        vector<int> freqBits(32);
        int res = -1;
        while(j < l){
            setFreqBits(freqBits, nums[j]);
            while(i <= j && countFreqBits(freqBits) >= k){
                if(res == -1){
                    res = j - i + 1;
                }
                else{
                    res = min(res, j-i+1);
                }
                unsetFreqBits(freqBits, nums[i]);
                i++;
            }
                j++;
        }
        return res;
    }
};