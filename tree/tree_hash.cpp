i64 dfs(int u){
    vector<i64> h;
    subtree_sz[u] = 1;
    for(i64 child : edge[u]){
        h.push_back(dfs(child));
        subtree_sz[u] += subtree_sz[child];
    }
    sort(h.begin(), h.end());
    i64 ret = subtree_sz[u];
    for(i64 v : h){
        ret = (ret * base + v) % MOD;
    }
    return ret;
}