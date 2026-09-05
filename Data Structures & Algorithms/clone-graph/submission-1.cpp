/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    map<Node*, Node*> mp;
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        
        if(mp.find(node) == mp.end()){
            Node* copy = new Node(node->val);
            mp[node] = copy;
            for(Node* neigh: node->neighbors){
                mp[node]->neighbors.push_back(cloneGraph(neigh));
            }
        }
        return mp[node];
    }
};
