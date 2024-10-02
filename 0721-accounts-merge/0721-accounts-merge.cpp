class Disjoint{
    public:
        vector<int> parent;
        Disjoint(int n){
            parent.resize(n+1, -1);
        }

        int find(int node){
            if(parent[node] < 0){
                return node;
            }
            return parent[node] = find(parent[node]);
        }

        void unionSize(int a, int b){
            int par_a = find(a);
            int par_b = find(b);
            if(par_a != par_b){
                if(parent[par_a] < parent[par_b]){
                    parent[par_a] += parent[par_b];
                    parent[par_b] = par_a;                    
                }
                else{
                    parent[par_b] += parent[par_a];
                    parent[par_a] = par_b;
                }
            }
        }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int> m;
        int l = accounts.size();
        Disjoint dj(l);
        for(int i = 0; i < l; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string email = accounts[i][j];
                if(m.find(email) == m.end()){
                    m[email] = i;
                }
                else{
                    dj.unionSize(m[email], i);
                }
            }
        }

        vector<vector<string>> res(l);
        for(int i = 0; i < l; i++){
            res[i].push_back(accounts[i][0]);
        }

        for(auto item : m){
            res[dj.find(item.second)].push_back(item.first);
        }

        vector<vector<string>> ans;
        for(auto item : res){
            if(item.size() > 1){
                sort(item.begin() + 1, item.end());
                ans.push_back(item);
            }
        }
        return ans;
    }
};