class Solution {
public:
    int isSetBitsEqual(int a, int b){
        int cnt1 = 0;
        int cnt2 = 0;
        while(a > 0 || b > 0){
            if(a > 0){
                cnt1++;
                a = a & (a - 1);
            }
            if(b > 0){
                cnt2++;
                b = b & (b-1);
            }
        }
        return cnt1 == cnt2;
    }

    bool canSortArray(vector<int>& nums) {
        // int prevMin = INT_MAX;
        int prevMax = INT_MIN;
        int i = 0, j = 0, l = nums.size();
        while(j < l){
            int curMax = INT_MIN;
            int curMin = INT_MAX;
            while(j < l && isSetBitsEqual(nums[i], nums[j])){
                curMax = max(nums[j], curMax);
                curMin = min(curMin, nums[j]);
                j++;
            }
            if(i != 0){
                if(prevMax > curMin) return false;
            }
            // prevMin = curMin;
            prevMax = curMax;
            i = j;

        }
        return true;
    }
};