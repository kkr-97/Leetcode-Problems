class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int l = nums.size();
        int n = 1 << l;
        vector<vector<int>> ans;
        for(int num = 0; num < n; num++){
            vector<int> temp;
            for(int i = 0; i < l; i++){
                if(num & (1 << i)){
                    temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};