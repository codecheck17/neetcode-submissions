class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses);

        for(int i = 0; i < n; i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            inDegree[a]++;
            adj[b].push_back(a);
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0)
                q.push(i);
        }

        vector<int> ordering;
        int finished = 0;
        while(!q.empty()){
            int a = q.front();
            q.pop();
            finished++;
            ordering.push_back(a);
            for(int b: adj[a]){
                inDegree[b]--;
                if(inDegree[b] == 0)
                    q.push(b);
            }
        }
        
        return finished == numCourses ? ordering : vector<int>();
    }
};
