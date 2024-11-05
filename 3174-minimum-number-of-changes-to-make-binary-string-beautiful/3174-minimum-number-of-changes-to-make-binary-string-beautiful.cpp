class Solution {
public:
    int minChanges(string s) {
        int l = s.size();
        int cnt = 0;

        for(int i = 0; i < l; i+=2){
            if(s[i] != s[i+1]) cnt++;
        }
        return cnt;
    }
};