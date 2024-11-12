class Solution {
public:
    static bool comparator(const vector<int>& v1, const vector<int>& v2){
        return v1[0] < v2[0];
    }

    int retrieveBtyItem(int q, vector<vector<int>>& items){
        int low = 0, high = items.size() - 1;
        int ans = 0;
        while(low <= high){
            int mid = (high - low) / 2 + low;
            if(items[mid][0] <= q){
                ans = max(ans, items[mid][1]);
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), comparator);
        int il = items.size();
        int ql = queries.size();
        vector<int> ans;
        for(int i = 0; i < il; i++){
            cout << items[i][0] << " " << items[i][1] << endl;
        }
        for (int i = 1; i < items.size(); i++) {
        items[i][1] = max(items[i][1], items[i - 1][1]);
    }
        for(int i = 0; i < ql; i++){
            ans.push_back(retrieveBtyItem(queries[i], items));
        }
        return ans;
    }
};