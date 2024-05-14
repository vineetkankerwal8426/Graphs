// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
// 4 4  -> 4 node and 4 number of edges
// 0 1  -> contains two space-separated integers denoting each edge.
// 1 2
// 2 3
// 3 3

    bool dfs(int v,vector<int> adj[],vector<bool> & vis, vector<bool>& pathvis){
        vis[v] = true;
        pathvis[v] = true;
        for(int i =0;i<adj[v].size();i++){
            if(!vis[adj[v][i]]){
                if(dfs(adj[v][i],adj,vis,pathvis)) return true;
            }else{
                if(pathvis[adj[v][i]]) return true;
            }
        }
        pathvis[v] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V);
        vector<bool> pathvis(V);
        for(int i =0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis)) return true;
            }
        }
        return false;
    }