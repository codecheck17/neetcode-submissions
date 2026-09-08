class DSU{
    int n;
    int numComponents;
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n){
        this->n = n;
        this->numComponents = n;
        parent = vector<int>(n);
        size = vector<int>(n);
        for(int i = 0; i < n ; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int node){
        if(parent[node] == node)
            return node;
        
        return parent[node] = find(parent[node]);
    }
    bool unionNodes(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv)
            return false;
        
        if(size[pu] < size[pv])
            swap(pu, pv);
        
        size[pu] += size[pv];
        parent[pv] = pu;
        numComponents--;
        return true;
    }
    int getComponents(){
        return numComponents;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> result;
        int n = edges.size();
        DSU dsu(n + 1);
        for(int i = 0; i < n; i++){
            int a = edges[i][0];
            int b = edges[i][1];
            if(!dsu.unionNodes(a, b)){
                result = edges[i];
            }
        }
        return result;
    }
};
