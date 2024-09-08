bool dfs(int u){
    for(int i : edge[u]){
        if(!vis[i]){ // 有連通且未拜訪
            vis[i] = true; // 紀錄是否走過
            if(match[i]==-1 || dfs(match[i])){  
                match[i] = u; match[u] = i; // 紀錄匹配
                return true;
            }
        }
    }
    return false;
}
int hungarian(){
    int ans = 0;
    memset(match, -1, sizeof(match));
    for(int i = 1 ;i <= lhs; i++){
        // 記得每次使用需清空vis陣列
        memset(vis, 0, sizeof(vis));
        if(dfs(i)) ans++;
    }
    return ans;
}