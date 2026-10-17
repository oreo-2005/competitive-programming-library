vector<vector<int>> bfs_grid(const vector<string>& S, const vector<pair<int, int>>& starts) {
    int H = S.size();
    int W = S[0].size();

    vector<vector<int>> dist(H, vector<int>(W, -1));
    queue<pair<int, int>> Q;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    for(auto [x, y] : starts) {
        if(dist[x][y] != -1 || S[x][y] == '#') continue;
        dist[x][y] = 0;
        Q.push({x, y});
    }

    while(!Q.empty()) {
        auto [x, y] = Q.front();
        Q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(S[nx][ny] == '#') continue;
            if(dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[x][y] + 1;
            Q.push({nx, ny});
        }
    }

    return dist;
}