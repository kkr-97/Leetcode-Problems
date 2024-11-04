class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int i = 0, j = 0;
        int len = word.size();
        while(j < len && i <= j){
            int win_size = 0;
            while(j < len && win_size < 9 && word[j] == word[i]){
                win_size++;
                j++;
            }
            comp += string(1, win_size + '0') + string(1, word[i]);
            i = j;
        }
        return comp;
    }
};