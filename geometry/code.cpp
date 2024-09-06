#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const ld eps = 1e-8, PI = acos(-1);
struct PT {  // 定義點
    int x, y;
    PT(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    PT operator+(const PT &a) const { return PT(x + a.x, y + a.y); }
    PT operator-(const PT &a) const { return PT(x - a.x, y - a.y); }
    PT operator*(const int &a) const { return PT(x * a, y * a); }
    PT operator/(const int &a) const { return PT(x / a, y / a); }
    int operator*(const PT &a) const {  // 計算幾何程式碼中內積通常用*表示
        return x * a.x + y * a.y;
    }
    int operator^(const PT &a) const {  // 計算幾何程式碼中外積通常用^表示
        return x * a.y - y * a.x;
    }
    int length2() { return x * x + y * y; }          // 回傳距離平方
    double length() { return sqrt(x * x + y * y); }  // 回傳距離
    bool operator<(const PT &a) const {  // 判斷兩點座標 先比 x 再比 y
        return x < a.x || (x == a.x && y < a.y);
    }
    friend int cross(const PT &o, const PT &a, const PT &b) {
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
    if (fabs(a - b) < eps) return 0;
    if (a < b) return -1;
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
CIRCLE getmec(vector<PT> &p) {
    int n = p.size();
    random_shuffle(p.begin(), p.end());
    CIRCLE c = {p[0], 0};
    for (int i = 1; i < n; i++) {
        if (judge(c.r, (c.o - p[i]).length()) == -1) {
            c = {p[i], 0};
            for (int j = 0; j < i; j++) {
                if (judge(c.r, (c.o - p[j]).length()) == -1) {
                    c = {(p[i] + p[j]) / 2, (p[i] - p[j]).length() / 2};
                    for (int k = 0; k < j; k++) {
                        if (judge(c.r, (c.o - p[k]).length()) == -1)
                            c = getcircle(p[i], p[j], p[k]);
                    }
                }
            }
        }
    }
    return c;
}
bool collinearity(const PT &a, const PT &b, const PT &c) {  // 是否三點共線
    return ((b - a) ^ (c - a)) == 0;
}
bool inLine(const PT &p, const LINE &li) {  // 是否在線段上
    PT st, ed;
    st = li.p, ed = st + li.v;
    return collinearity(st, ed, p) && (st - p) * (ed - p) < 0;
}
inline bool xiangjiao(LINE &line1, LINE &line2) {  // 是否相交
    PT l1st = line1.p, l1ed = line1.p + line1.v;
    PT l2st = line2.p, l2ed = line2.p + line2.v;
    if (inLine(l1st, line2) || inLine(l1ed, line2) || inLine(l2st, line1) ||
        inLine(l2ed, line1))
        return 1;
    PT A = l1st, B = l1ed, C = l2st, D = l2ed;
    PT AB = B - A, AC = C - A, AD = D - A, CD = D - C, CA = A - C, CB = B - C;
    if (((AB ^ AC) * (AB ^ AD) < 0) && ((CD ^ CA) * (CD ^ CB) < 0)) return 1;
    return 0;
}
int dcmp(ld x) {
    if (abs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}
