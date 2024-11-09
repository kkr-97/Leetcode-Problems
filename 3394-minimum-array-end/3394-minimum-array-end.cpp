class Solution {
public:
    long long minEnd(int n, int x) {
        long long targetExt = n-1;
        long long ans = x;

        int xBit = 0, nBit = 0;
        
        while(xBit < 64){
            if((ans>>xBit)&1){
                xBit++;
                continue;
            }
            if((targetExt>>nBit)&1){
                ans = ans | (1LL << xBit);
            }
            nBit++;
            xBit++;
        }
        return ans;
    }
};