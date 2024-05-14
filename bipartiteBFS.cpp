// Given an adjacency list of a graph adj of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.



    bool bfs(int v,vector<int> adj[],vector<int> & col){
        //   vector<int> col(V,-1);
	    queue<int> q;
	    q.push(v);
	    col[v] =0;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        for(int i =0;i<adj[node].size();i++){
	            if(col[adj[node][i]]==-1){
	                q.push(adj[node][i]);
	                col[adj[node][i]] = (col[node]==1)? 0: 1;
	            }else{
	                if(col[adj[node][i]]==col[node]) return false;   // check if adjecent node also have same color
	            }
	        }
	    }
	    return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> col(V,-1);  //color vector, initially assined -1;
	    for(int i =0;i<V;i++){  // to check every subgraph in a forest
	        if(col[i]==-1){
	            if(!bfs(i,adj,col)) return false;
	        }
	    }
	    return true;
	}