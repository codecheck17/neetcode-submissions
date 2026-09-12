class DSU {
        vector<int> par;
        vector<int> sze;
        int n;
    public:
        DSU(int n){
            this->n = n;
            par = vector<int>(n);
            sze = vector<int>(n);
            for(int i = 0; i < n; i++){
                par[i] = i;
                sze[i] = 1;
            }
        }

        int findPar(int node){
            if(par[node] == node)
                return node;
            
            return par[node] = findPar(par[node]);
        }

        bool unionNodes(int a, int b){
            if(a == b)
                return true;
            
            int para = findPar(a);
            int parb = findPar(b);
            if(para == parb)
                return false;
            
            if(sze[para] < sze[parb])
                swap(para, parb);
            
            par[parb] = para;
            sze[para] += sze[parb];
            return true;
        }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edgesWithCost;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int dist = abs(points[i][1] - points[j][1]) + abs(points[i][0] - points[j][0]);
                edgesWithCost.push_back({dist, i, j});
            }
        }
        sort(edgesWithCost.begin(), edgesWithCost.end());
        DSU dsu(n);
        int minCost = 0;
        for(int i = 0; i < edgesWithCost.size(); i++){
            int cost = edgesWithCost[i][0];
            int a = edgesWithCost[i][1];
            int b = edgesWithCost[i][2];

            if(dsu.unionNodes(a, b)){
                minCost += cost;
            }
        }
        return minCost;
    }
};
