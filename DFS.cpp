//dfs traversal of the graph
//You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
//Note: Use the recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.
//example Input: V = 5 , adj = [[2,3,1] , [0], [0,4], [0], [2]]


    void dfs(int node,vector<int> adj[],vector<bool> & visited,vector<int> &ans){
        visited[node] = true;
        ans.push_back(node);
        for(int i =0;i<adj[node].size();i++){
            if(visited[adj[node][i]] == false){
                dfs(adj[node][i],adj,visited,ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,false);
        vector<int> ans;
        dfs(0,adj,visited,ans);
        return ans;
    }
// we can also use stack instead of recursion 