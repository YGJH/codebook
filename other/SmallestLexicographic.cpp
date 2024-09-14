//對於可化作DAG的回朔問題求最小字典序的選擇
//建反圖 (反著做回來) (把以 i 結尾變成 以 i 開頭)
//結論 : i <- j (i < j) 取最小的 a[j]
for(int j = N; j; --j) {
    for(auto i:E[j])
    dp[i] = min(dp[i],dp[j]);
}