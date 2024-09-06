#define cl(x) (x << 1)
#define cr(x) (x << 1) + 1

struct segTree {
#define MXN 200500
    int n;
    // vector<int> seg;
    // vector<int> arr, tag;
    int seg[MXN], arr[MXN], tag[MXN];
    void init(int a) {
        n = a;
        // seg.resize(4 * (n + 5), 0);
        // tag.resize(4 * (n + 5), 0);
        // arr.resize(n + 5, 0);
        for (int i = 0; i < n + 5; i++)
            arr[i] = 0;
        for (int i = 0; i < 4 * (n + 5); i++)
            seg[i] = tag[i] = 0;
    }
    void push(int id, int l, int r) {
        if (tag[id] != 0) {
            seg[id] += tag[id] * (r - l + 1);
            if (l != r) {
                tag[cl(id)] += tag[id];
                tag[cr(id)] += tag[id];
            }
            tag[id] = 0;
        }
    }
    void pull(int id, int l, int r) {
        int mid = (l + r) >> 1;
        push(cl(id), l, mid);
        push(cr(id), mid + 1, r);
        int a = seg[cl(id)];
        int b = seg[cr(id)];
        seg[id] = a + b;
    }
    void build(int id, int l, int r) {
        if (l == r) {
            seg[id] = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(cl(id), l, mid);
        build(cr(id), mid + 1, r);
        pull(id, l, r);
    }
    void update(int id, int l, int r, int ql, int qr, int v) {
        push(id, l, r);
        if (ql <= l && r <= qr) {
            tag[id] += v;
            return;
        }
        int mid = (l + r) >> 1;
        if (ql <= mid)
            update(cl(id), l, mid, ql, qr, v);
        if (qr > mid)
            update(cr(id), mid + 1, r, ql, qr, v);
        pull(id, l, r);
    }
    int query(int id, int l, int r, int ql, int qr) {
        push(id, l, r);
        if (ql <= l && r <= qr) {
            return seg[id];
        }
        int mid = (l + r) >> 1;
        int ans1, ans2;
        bool f1 = 0, f2 = 0;
        if (ql <= mid) {
            ans1 = query(cl(id), l, mid, ql, qr);
            f1 = 1;
        }
        if (qr > mid) {
            ans2 = query(cr(id), mid + 1, r, ql, qr);
            f2 = 1;
        }
        if (f1 && f2)
            return ans1 + ans2;
        if (f1)
            return ans1;
        return ans2;
    }
    void build() { build(1, 1, n); }
    int query(int ql, int qr) { return query(1, 1, n, ql, qr); }
    void update(int ql, int qr, int val) { update(1, 1, n, ql, qr, val); }
};