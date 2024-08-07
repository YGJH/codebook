vector<int> prefix_func(const string& s){
	int n = s.size();
	vector<int> pi(n);
	for(int i=1,j=0;i<n;++i){
		int j = pi[i-1];
		while(j && s[j] != s[i]) j = pi[j-1]; //取次小LCP
		if(s[j] == s[i]) ++j;
		pi[i] = j;
	}
	return pi;
}