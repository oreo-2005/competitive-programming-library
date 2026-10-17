vector<int> bfs(int start, const vector<vector<int>>& G) {
    vector<int> dist(G.size(), -1);
    queue<int> Q;

    dist[start] = 0;
    Q.push(start);

    while(!Q.empty()) {
        int v = Q.front();
        Q.pop();

        for(int nex : G[v]) {
            if(dist[nex] != -1) continue;

            dist[nex] = dist[v] + 1;
            Q.push(nex);
        }
    }

    return dist;
}