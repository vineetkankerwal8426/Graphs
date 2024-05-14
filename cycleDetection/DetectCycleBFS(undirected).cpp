// Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, 
// check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.


bool isCycle(int V, vector<int> adj[]) {
        // Code heref
        vector<bool> vis(V);
        queue<pair<int,int>> q;
        q.push({0,-1});
        vis[0] = true;
        while(!q.empty()){
            int node= q.front().first;
            int parent = q.front().second;
            q.pop();
            for(int i =0;i<adj[node].size();i++){
                if(!vis[adj[node][i]]){
                    q.push({adj[node][i],node});
                    vis[adj[node][i]] = true;
                }
                else{
                    if(adj[node][i]!= parent) return true;
                }
                
            }
        }
        return false;
    }