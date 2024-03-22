// bfs traversal of graph
   
//Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
//Note: One can move from node u to node v only if there's an edge from u to v. Find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the input graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.
   
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,0);
        vector<int> ans;
        queue<int> q;
        q.push(0);
        visited[0] =1;
        while(!q.empty()){
            int temp = q.front();
            ans.push_back(temp);
            q.pop();
            for(int i =0;i<adj[temp].size();i++){
                if(visited[adj[temp][i]]==false){
                    q.push(adj[temp][i]);
                    visited[adj[temp][i]]= true;
                }
            }
        }
        return ans;
    }
