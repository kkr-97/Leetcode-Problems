class Solution {
public:
    int romanToInt(string s) {
        int l = s.length();
        if(l == 0) return 0;
        map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int res = 0;
        for(int i = 0; i < l -1; i++){
            char cur_ch = s[i];
            char nxt_ch = s[i+1];
            if(m[cur_ch] < m[nxt_ch]){
                res -= m[cur_ch];
            }
            else{
                res += m[cur_ch];
            }
        }
        res += m[s[l-1]];
        return res;
    }
};