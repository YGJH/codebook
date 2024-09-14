vector<int> zfunc(string &s){ //求 s 跟 s[i..n-1] 的最長真共同前綴長度 z[0] = 0
	int n = s.size();
	vector<int> z(n);
	for(int i = 1,l = 0,r = 0; i < n;++i){
		if(i <= r && z[i - l] < r - i + 1) z[i] = z[i - l];
		else {
			z[i] = max(0LL,r - i + 1);
			while(i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
		}
		if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}
	return z;
}