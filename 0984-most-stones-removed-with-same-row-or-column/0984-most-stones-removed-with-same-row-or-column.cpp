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

        void unionBySize(int a, int b){
            int up_a = find(a);
            int up_b = find(b);
            if(up_a != up_b){
                if(parent[up_a] < parent[up_b]){
                    parent[up_a] += parent[up_b];
                    parent[up_b] = up_a;
                }
                else{
                    parent[up_b] += parent[up_a];
                    parent[up_a] = up_b;
                }
            }
        }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int l = stones.size();
        int maxR = 0;
        int maxC = 0;
        for(int i = 0; i < l; i++){
            maxR = max(maxR, stones[i][0]);
            maxC = max(maxC, stones[i][1]);
        }
        int size = maxR + maxC + 1;
        Disjoint dj(size);
        for(auto item : stones){
            int r = item[0];
            int c = item[1] + maxR + 1;
            dj.unionBySize(r, c);
        }
        int compo = 0;
        for(int i = 0; i < size + 1; i++){
            if(dj.parent[i] < -1){
                compo++;
            }
        }

        return l - compo;
    }
};