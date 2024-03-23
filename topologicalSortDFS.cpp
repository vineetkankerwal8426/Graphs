//Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

	void dfs(int node,vector<int> adj[],vector<bool>& vis,stack<int> & s){
	    if (vis[node]){
	        return;
	    }
	    vis[node] = 1;
	    for(int i:adj[node]){
	        dfs(i,adj,vis,s);
	    }
	    s.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> ans;
	    vector<bool>vis(V,0);
	    stack<int> s;
	    for(int i =0;i<V;i++){
	        
	        dfs(i,adj,vis,s);
	    }
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}