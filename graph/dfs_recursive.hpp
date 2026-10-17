void dfs(int v, const vector<vector<int>>& G, vector<bool>& visited) {
    visited[v] = true;

    for(int nex : G[v]) {
        if(visited[nex]) continue;
        dfs(nex, G, visited);
    }
}