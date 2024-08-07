template<class T>
struct pt{
	T x,y;
	pt(T _x,T _y):x(_x),y(_y){}
	pt():x(0),y(0){}
	
	pt operator * (T  c){ return pt(x*c,y*c);}
	pt operator / (T  c){ return pt(x/c,y/c);}
	pt operator + (pt a){ return pt(x+a.x,y+a.y);}
	pt operator - (pt a){ return pt(x-a.x,y-a.y);}
	T  operator * (pt a){ return x*a.x + y*a.y;}
	T  operator ^ (pt a){ return x*a.y - y*a.x;}

	auto operator<=>(pt o) const { return (x != o.x) ? x <=> o.x : y <=> o.y; }
	bool operator < (pt a) const { return x < a.x || (x == a.x && y < a.y);};
	bool operator== (pt a) const { return x == a.x and y == a.y;};
};

using numbers::pi;
using ld = long double;
const ld eps = 1e-8L;
using Pt = pt<ld>;

int dcmp(ld x) { return (x > -eps) - (x < eps); }
ld ori(Pt a, Pt b, Pt c) { return (b - a) ^ (c - a); }
ld abs(Pt a) { return sqrt(a * a); }
ld abs2(Pt a) { return a * a; }

istream &operator>>(istream &s, Pt &a) { return s >> a.x >> a.y; }
ostream &operator<<(ostream &s, Pt &a) { return s << "(" << a.x << ", " << a.y << ")";} 
