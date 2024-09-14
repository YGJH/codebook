mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
struct treap {
	treap *l, *r;
	int sz, pri, key;
	int tag;
	treap(int key_) : tag(0), key(key_), pri(gen()), sz(1) { l = r = nullptr; }
};
treap *root = nullptr;
int Size(treap *a) { return a ? a->sz : 0; }
void pull(treap *a) { a->sz = Size(a->l) + Size(a->r) + 1; }

void push(auto x) {
    if(x->tag) {
        x->key += x->sz * x->tag;
        if(x->l) x->l->tag += x->tag;
        if(x->r) x->r->tag += x->tag;
        x->tag = 0;
    }
}
treap *merge(treap *a, treap *b) {
	if (!a || !b)
		return a ? a : b;
	if (a->pri > b->pri) {
        push(a);
		a->r = merge(a->r, b);
		pull(a);
		return a;
	} else {
        push(b);
		b->l = merge(a, b->l);
		pull(b);
		return b;
	}
}

void split_by_size(treap *x, int k, treap *&a, treap *&b) {
	if (!x) {
		a = b = nullptr;
		return;
	}
	push(x);
	if (Size(x->l) + 1 <= k) {
		a = x;
		split_by_size(x->r, k - Size(x->l) - 1, a->r, b);
		pull(a);
	} else {
		b = x;
		split_by_size(x->l, k, a, b->l);
		pull(b);
	}
}
void split_by_key(treap *x, int k, treap *&a, treap *&b) {
	if (!x) {
		a = b = nullptr;
		return;
	}
    push(x);
	if (x->key <= k) {
		a = x;
		split_by_key(x->r, k, a->r, b);
		pull(a);
	} else {
		b = x;
		split_by_key(x->l, k, a, b->l);
		pull(b);
	}
}
void insert(int x) {
	treap *a, *b;
	split_by_key(root, x, a, b);
	root = merge(a, merge(new treap(x), b));
}
void erase(int x) {
    treap *a , *b , *mid;
    split_by_key(root , x , a ,b);
    split_by_key(a , x-1 , a , mid);
    merge(merge(a, merge(mid->l , mid->r)) , b);
}
void add_range(int val ,int L , int R) {
    treap *l , *r , *m;
    split_by_key(root , R , l , r);
    split_by_key(l , L-1 , l , m);
    m->tag += val;
    merge(l , merge(m , r));
}
int size_of(int x, treap *now) {
	if (!now) {
		return 0;
	}
	if (now->key <= x) {
		return 1 + Size(now->l) + size_of(x, now->r);
	} else {
		return size_of(x, now->l);
	}
}
inline void build() {
	for (int i = 0; i < n; i++) {
		root = merge(root, new treap(arr[i]));
	}
}