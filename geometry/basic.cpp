const ld eps = 1e-8, PI = acos(-1);
struct PT {  // 定義點
    int x, y;
    PT(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    bool operator==(const PT& a) const { return a.x == x && a, y == y; }
    PT operator+(const PT& a) const { return PT(x + a.x, y + a.y); }
    PT operator-(const PT& a) const { return PT(x - a.x, y - a.y); }
    PT operator*(const int& a) const { return PT(x * a, y * a); }
    PT operator/(const int& a) const { return PT(x / a, y / a); }
    int operator*(const PT& a) const {  // 計算幾何程式碼中內積通常用*表示
        return x * a.x + y * a.y;
    }
    int operator^(const PT& a) const {  // 計算幾何程式碼中外積通常用^表示
        return x * a.y - y * a.x;
    }
    int length2() { return x * x + y * y; }          // 回傳距離平方
    double length() { return sqrt(x * x + y * y); }  // 回傳距離
    bool operator<(const PT& a) const {  // 判斷兩點座標 先比 x 再比 y
        return x < a.x || (x == a.x && y < a.y);
    }
    friend int cross(const PT& o, const PT& a, const PT& b) {
        PT lhs = o - a, rhs = o - b;
        return lhs.x * rhs.y - lhs.y * rhs.x;
    }
};
struct CIRCLE {  // 圓心，半徑
    PT o;
    ld r;
};
struct LINE {  // 點， 向量
    PT p, v;
};
int judge(ld a, ld b) {  // 判斷浮點數大小
    // 等於回傳0，小於回傳-1，大於回傳1
    if (fabs(a - b) < eps)
        return 0;
    if (a < b)
        return -1;
    return 1;
}
PT zhixianjiaodian(LINE a, LINE b) {  // 求兩直線交點
    PT u = a.p - b.p;
    ld t = (b.v ^ u) / (a.v ^ b.v);
    return a.p + (a.v * t);
}
PT zhuanzhuan(PT a, ld angle) {  // 向量旋轉
    return {a.x * cos(angle) + a.y * sin(angle),
            -a.x * sin(angle) + a.y * cos(angle)};
}
LINE bisector(PT a, PT b) {  // 中垂線
    PT p = (a + b) / 2;
    PT v = zhuanzhuan(b - a, PI / 2);
    return {p, v};
}
CIRCLE getcircle(PT a, PT b, PT c) {  // 三點求外接圓
    auto n = bisector(a, b), m = bisector(a, c);
    PT o = zhixianjiaodian(n, m);
    ld r = (o - a).length();
    return {o, r};
}
bool collinearity(const PT& a, const PT& b, const PT& c) {  // 是否三點共線
    return ((b - a) ^ (c - a)) == 0;
}
bool inLine(const PT& p, const LINE& li) {  // 是否在線段上
    PT st, ed;
    st = li.p, ed = st + li.v;
    return collinearity(st, ed, p) && (st - p) * (ed - p) < 0;
}
int dcmp(ld x) {
    if (abs(x) < eps)
        return 0;
    else
        return x < 0 ? -1 : 1;
}
Pt LLIntersect(Line a, Line b) {
    Pt p1 = a.s, p2 = a.e, q1 = b.s, q2 = b.e;
    ld f1 = (p2 - p1) ^ (q1 - p1), f2 = (p2 - p1) ^ (p1 - q2), f;
    if (dcmp(f = f1 + f2) == 0)
        return dcmp(f1) ? Pt(NAN, NAN) : Pt(INFINITY, INFINITY);
    return q1 * (f2 / f) + q2 * (f1 / f);
}
int ori(const Pt& o, const Pt& a, const Pt& b) {
    LL ret = (a - o) ^ (b - o);
    return (ret > 0) - (ret < 0);
}
// p1 == p2 || q1 == q2 need to be handled
bool banana(const Pt& p1, const Pt& p2, const Pt& q1, const Pt& q2) {
    if (((p2 - p1) ^ (q2 - q1)) == 0) {  // parallel
        if (ori(p1, p2, q1))
            return false;
        return ((p1 - q1) * (p2 - q1)) <= 0 || ((p1 - q2) * (p2 - q2)) <= 0 ||
               ((q1 - p1) * (q2 - p1)) <= 0 || ((q1 - p2) * (q2 - p2)) <= 0;
    }
    return (ori(p1, p2, q1) * ori(p1, p2, q2) <= 0) &&
           (ori(q1, q2, p1) * ori(q1, q2, p2) <= 0);
}
