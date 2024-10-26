class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int l = nums.size();
        for(int i = l -1; i > 0; i--){
            if(nums[i] > nums[i - 1]){
                ind = i - 1;
                break;
            }
        }
        if(ind == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        int ind2 = -1;
        for(int i = l - 1; i > ind; i--){
            if(nums[i] > nums[ind]){
                ind2 = i;
                break;
            }
        }
        cout << ind2;
        int temp = nums[ind];
        nums[ind] = nums[ind2];
        nums[ind2] = temp;

        reverse(nums.begin() + ind +1, nums.end());

    }
};