void dfs(int start, const vector<vector<int>>& G, vector<bool>& visited) {
    stack<int> st;
    st.push(start);
    visited[start] = true;

    while(!st.empty()) {
        int v = st.top();
        st.pop();

        for(int nex : G[v]) {
            if(visited[nex]) continue;
            visited[nex] = true;
            st.push(nex);
        }
    }
}