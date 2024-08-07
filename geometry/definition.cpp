#define pi acos(-1)
using ld = long double;
const ld eps = 1e-8;
int dcmp(ld x) {
  if(abs(x) < eps) return 0;
  else return x < 0 ? -1 : 1;
}

template<class T>
struct pt{
	T x,y;
	pt(T _x,T _y):x(_x),y(_y){}
	pt():x(0),y(0){}
	
	pt operator * (const T  &c) const { return pt(x*c,y*c);}
	pt operator / (const T  &c) const { return pt(x/c,y/c);}
	pt operator + (const pt &a) const { return pt(x+a.x,y+a.y);}
	pt operator - (const pt &a) const { return pt(x-a.x,y-a.y);}
	T  operator * (const pt &a) const { return x*a.x + y*a.y;}
	T  operator ^ (const pt &a) const { return x*a.y - y*a.x;}

	bool operator < (const pt &a) const { return x < a.x || (x == a.x && y < a.y);};
	bool operator == (const pt &a) const { return dcmp(x-a.x) && dcmp(y-a.y);};
};
using Pt = pt<ld>;

istream &operator>>(istream &s, Pt &a) { return s >> a.x >> a.y; }
ostream &operator<<(ostream &s, Pt &a) { return s << "(" << a.x << ", " << a.y << ")";} 
