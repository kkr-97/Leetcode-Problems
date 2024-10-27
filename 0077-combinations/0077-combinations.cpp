class Solution {
    vector<vector<int>> ans;

    void dfs(int cur, int n, int k, int depth, vector<int> &temp){
        if(depth >= k){
            ans.push_back(temp);
            
            return;
        }


        for(int i = cur; i <= n; i++){
            temp.push_back(i);
            dfs(i+1, n, k, depth + 1, temp);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        dfs(1, n, k, 0, temp);
        return ans;
    }
};