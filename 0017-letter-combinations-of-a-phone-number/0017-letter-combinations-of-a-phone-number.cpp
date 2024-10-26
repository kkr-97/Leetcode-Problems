class Solution {
    unordered_map<int, string> m = {{1 , ""}, {2 , "abc"},{3, "def"}, 
                                        {4, "ghi"}, {5, "jkl"}, {6, "mno"},
                                        {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
    vector<string> ans;

    void dfs(int depth, string digits, string cur_str){
        if(cur_str.size() == digits.size()){
            ans.push_back(cur_str);
            return;
        }
        
        for(char ch : m[digits[depth] - '0']){
            dfs(depth + 1, digits, cur_str + string(1, ch));
        }

    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        int depth = 0;
        dfs(depth, digits, "");
        return ans;
    }
};