class Solution {
    vector<int> disc, low;
    vector<vector<int>> ans;
    int timer = 0;
    vector<vector<int>> adj;

    void dfs(int cur, int par, vector<bool> &visited){
        visited[cur] = true;
        disc[cur] = low[cur] = timer++;
        for(int nn : adj[cur]){
            if(nn == par) continue;
            if(!visited[nn]){
                dfs(nn, cur, visited);
                low[cur] = min(low[nn], low[cur]);
                if(disc[cur] < low[nn]){
                    ans.push_back({cur, nn});
                }
            }
            else{
                low[cur] = min(low[nn], low[cur]);
            }
        }
    }

    void createAdjLst(int n, vector<vector<int>>& connections){
        adj.resize(n);
        for(auto val : connections){
            int a = val[0];
            int b = val[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        createAdjLst(n, connections);
        disc.resize(n);
        low.resize(n);
        vector<bool> visited(n, false);
        dfs(0, -1, visited);
        return ans;
    }
};