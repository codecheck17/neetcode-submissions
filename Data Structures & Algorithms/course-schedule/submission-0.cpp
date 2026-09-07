class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inCount(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        int n = prerequisites.size();
        for(int i = 0; i < n; i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            adj[a].push_back(b);
            inCount[b]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inCount[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(int neigh: adj[front]){
                inCount[neigh]--;
                if(inCount[neigh] == 0){
                    q.push(neigh);
                }
            }
        }
        for(int i = 0; i < numCourses; i++){
            if(inCount[i] != 0)
                return false;
        }
        return true;
    }
};
