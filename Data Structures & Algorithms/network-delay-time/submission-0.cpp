class Solution {
    static constexpr int inf = INT_MAX;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n, inf);
        vector<vector<pair<int,int>>> adj(n);
        for(vector<int>& time: times){
            int a = time[0] - 1;
            int b = time[1] - 1;
            int w = time[2];

            adj[a].push_back({b, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k - 1});
        dist[k - 1] = 0;
        while(!pq.empty()){
            pair<int, int> top = pq.top();
            pq.pop();

            int currDist = top.first;
            int node = top.second;
            for(pair<int, int> neigh: adj[node]){
                int next = neigh.first;
                int w = neigh.second;
                if(dist[next] == inf || dist[node] + w < dist[next]){
                    dist[next] = dist[node] + w;
                    pq.push({dist[next], next});
                } 
            }
        }

        int minTime = 0;
        for(int i = 0; i < n; i++){
            if(dist[i] == inf)
                return -1;
            
            minTime = max(minTime, dist[i]);
        }
        return minTime;
    }
};
