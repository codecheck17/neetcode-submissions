class Solution {
public:
    bool oneDiff(string &s, string &t, int len){
        int diff = 0;
        for(int i = 0; i < len; i++){
            if(s[i] != t[i])
                diff++;
        }
        return diff == 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord)
            return 0;
        
        wordList.push_back(beginWord);
        int n = wordList.size();
        int len = wordList[0].size();
        vector<vector<int>> adj(n);
        vector<bool> visited(n);
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(oneDiff(wordList[i], wordList[j], len)){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        queue<int> q;
        int ladderLen = 0;
        q.push(n-1);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int curr = q.front();
                q.pop();
                
                if(wordList[curr] == endWord)
                    return ladderLen + 1;
                
                for(int neigh: adj[curr]){
                    if(!visited[neigh]){
                        visited[neigh] = true;
                        q.push(neigh);
                    }
                }
            }
            ladderLen++;
        }
        return 0;
    }
};
