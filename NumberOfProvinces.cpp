// find how many subgraphs are there in a forest
/*
Input:
[
 [1, 0, 1],
 [0, 1, 0],
 [1, 0, 1]
]
*/

    void dfs(vector<vector<int>>&adj,int v,vector<bool>& visited){
        if(visited[v]) return;
        visited[v] = true;
        
        for(int i =0;i<adj[v].size();i++){
            if(adj[v][i]==1){
                if(!visited[i]){
                    dfs(adj,i,visited);
                }
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int ans =0;
        vector<bool> visited(V);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                ans +=1;
                dfs(adj,i,visited);
            }
        }
        return ans;
    }