void calcH(i64 &t, i64 &h, const i64 p) {
	i64 tmp=p-1; for(t=0;(tmp&1)==0;tmp/=2) t++; h=tmp;
}
// solve equation x^2 mod p = a
// !!!! (a != 0) !!!!!
bool solve(i64 a, i64 p, i64 &x, i64 &y) {
	if(p == 2) { x = y = 1; return true; }
	int p2 = p / 2, tmp = mypow(a, p2, p);
	if (tmp == p - 1) return false;
	if ((p + 1) % 4 == 0) {
		x=mypow(a,(p+1)/4,p); y=p-x; return true;
	} else {
		i64 t, h, b, pb; calcH(t, h, p);
		if (t >= 2) {
			do {b = rand() % (p - 2) + 2;
			} while (mypow(b, p / 2, p) != p - 1);
			pb = mypow(b, h, p);
		} int s = mypow(a, h / 2, p);
		for (int step = 2; step <= t; step++) {
			int ss = (((i64)(s * s) % p) * a) % p;
			for(int i=0;i<t-step;i++) ss=mul(ss,ss,p);
			if (ss + 1 == p) s = (s * pb) % p;
      		pb = ((i64)pb * pb) % p;
		} x = ((i64)s * a) % p; y = p - x;
	} return true; 
}
