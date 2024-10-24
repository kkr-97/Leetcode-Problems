class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        int i = 0, j = 0;
        string ans = "";
        while(i < min(strs[0].size(), strs[1].size())){
            if(strs[0][i] != strs[1][i]){
                break;
            }
            i++;
        }
        for(int j = 2; j < strs.size(); j++){
            while(i >= 0 && strs[0].substr(0, i) != strs[j].substr(0, i)){
                i--;
            }
        }

        return strs[0].substr(0, i);
    }
};