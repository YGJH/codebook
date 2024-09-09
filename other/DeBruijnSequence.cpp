//求由所有 N 長度bitstring作為substring 最短的字串 B(2,N) //B(k,N) : 以k個字元作為N長度字串節點
//00110 -> 00 01 11 10
//建圖 : 點為substrings 邊用 0 1 連接
//走訪 : 000 -1-> 001 
// 解為 Hamiltonian 路徑 (剛好所有節點走過一遍)
// 可同構到 N-1 圖上的Eulerian Circuit (每條邊 N-1 圖上的邊 代表 N 圖上的一個點)
vector<int> edges[1<<(N-1)];
vector<int> ans;
void dfs(int x){ // Eulerian Circuit 
    while(edges[x].size()){
        int u = edges[x].back();
        edges[x].pop_back();
        ans.push_back(u&1);
        dfs(u);
    }
}
void solve(int n){
    if(n == 1) {
        ans = {1,0};
        return;
    }
     for(int i = 0; i < (1<<(n-1)); ++i){
        edges[i].push_back((i<<1)&((1<<(n-1))-1)); // 0 的邊
        edges[i].push_back(((i<<1)+1)&((1<<(n-1))-1)); // 1 的邊
    }
    for(int i = 0; i < n-1;++i) ans.push_back(0); //初始狀態
    dfs(0);
}