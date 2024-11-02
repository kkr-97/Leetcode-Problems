class Solution {
public:
    bool isCircularSentence(string sentence) {
        int l = sentence.size();
        if(sentence[0] != sentence[l-1]) return false;
        int low = 0, high = 0;

        while(high < l){
            while(high < l && sentence[high] != ' '){
                high++;
            }
            low = high - 1;
            high++;
            if(high >= l) return true;
            if(sentence[low] != sentence[high]){
                cout << sentence[low] << " " << sentence[high];
                return false;
            }
        }
        return true;
    }
};