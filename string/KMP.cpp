vector<int> prefix_func(const string& s){
	int n = s.size();
	vector<int> pi(n);
	for(int i=1,j=0;i<n;++i){
		j = pi[i-1];
		while(j && s[j] != s[i]) j = pi[j-1]; //取次小LCP
		if(s[j] == s[i]) ++j;
		pi[i] = j;
	}
	return pi;
}
vector<int> kmp(string str, string s, vector<int>& nxt) {
    vector<int> ans;
    for (int i = 0, j = 0; i < SZ(str); i++) {
        while (j && str[i] != s[j]) j = nxt[j - 1];
        if (str[i] == s[j]) j++;
        if (j == SZ(s)) {
            ans.push_back(i - SZ(s) + 1);
            j = nxt[j - 1];
        }
    }
    return ans;
}
