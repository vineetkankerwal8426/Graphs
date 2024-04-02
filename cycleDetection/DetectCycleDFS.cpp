    bool dfs(int node ,int parent,vector<int> adj[],vector<bool>  visited){ //we can also say parent as a previous node
        visited[node] = true;
        for(int i =0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                if(dfs(adj[node][i],node,adj,visited)) return true;;
            }else{
                if(parent!=adj[node][i]) return true;; //if their is any visited node and it is not the previous node from where we are comming 
                // it means that we are in a loop where that node meets us again
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]){
        vector<bool> visited(V);
        for(int i =0;i<V;i++){// this loop is only for the forest if their are more than one component in a single graph with connected;  
            if(dfs(i,-1,adj,visited)) return true;
        }
        return false;
    }