class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int val : nums){
            m[val]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto item : m){
           
            pq.push({item.second, item.first});
             if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> ans;
        while(!pq.empty()){
            int val = pq.top().second;
            ans.push_back(val);
            pq.pop();
        }

        return ans;
    }
};