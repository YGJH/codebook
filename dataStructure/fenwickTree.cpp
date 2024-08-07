struct fenwick{
	#define lowbit(x) (x&-x)
	int n;
	vector<int> v;
	fenwick(int _n) : n(_n+1),v(_n+2){}
	void update(int x,int u){
		++x;
		for(;x < n; x += lowbit(x)) v[x] += u;
	}
	int query(int x){
		++x; int ret = 0;
		for(; x ; x -= lowbit(x)) ret += v[x];
		return ret;
	}
	int query(int l,int r) { return query(r) - query(l-1); }
	int kth(int k){ // lower_bound(k)
		int x = 0;
		--k;
		for(int i = (1<<__lg(n)); i;i >>= 1){
			if(x + i <= n and k >= v[x + i]){
				x += i; k -= v[x];
			}
		}
		return x;
	}

};
