class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        char prev = '_';
        int cur_cnt = 1;
        for(char ch : s){
            if(ch == prev){
                cur_cnt++;
                if(cur_cnt == 3){
                    cur_cnt--;
                    continue;
                }
            }
            else{
                cur_cnt = 1;
            }
            res += string(1, ch);
            prev = ch;
        }

        return res;
    }
};