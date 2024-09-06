struct STRUCT_BIT {
    int n;
    vector<int> bit;
    int lowbit(int x) { return x & -x; }
    void init(int _n) {
        n = _n + 1;
        bit = vector<int>(n, 0);
    }
    void update(int x, int v) {
        for (; x < n; x += lowbit(x)) {
            bit[x] += v;
        }
    }
    int query(int x) {
        int ret = 0;
        for (; x > 0; x -= lowbit(x)) {
            ret += bit[x];
        }
        return ret;
    }
};