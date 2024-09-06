#include <bits/stdc++.h>
using namespace std;
#define masterspark ios::sync_with_stdio(0), cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);

template<class F, class S> ostream &operator<<(ostream &s, pair<F, S> &v) { return s << "(" << v.first << ", " << v.second << ")";} 
template<class F, class S> istream &operator>>(istream &s, pair<F, S> &v) { return s >> v.first >> v.second; }
template<class T> istream &operator>>(istream &s, vector<T> &a) { for (auto &x:a) s>>x; return s; }
template<class T> ostream &operator<<(ostream &s, vector<T> &a) { int n=a.size(); if (!n) return s; s<<a[0]; for (int i=1; i<n; i++) s<<' '<<a[i]; return s; }
 
#define int long long
#define pp pair<int, int>
#define ff first
#define ss second

#define forr(i,n) for(int i = 1; i <= n;++i)
#define rep(i,j,n) for(int i = j; i < n;++i)
#define PB push_back
#define PF push_front
#define EB emplace_back
#define all(v) (v).begin(), (v).end()
#define FZ(x) memset(x, 0, sizeof(x)) //fill zero
#define SZ(x) ((int)x.size())
using i128 = __int128;
using i64 = __int64;
using i32 = __int32;

void solve(){
    
}
signed main()
{
    masterspark
    int t = 1;
    // freopen("stdin","r",stdin);
    // freopen("stdout","w",stdout);
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
} 