//趕時間抄這份 (只要3行)
template<class T> ostream &operator<<(ostream &s, const complex<T> &v) { return s << "(" << v.real() << ", " << v.imag() << ")";}
template<class T> istream &operator>>(istream &cin, complex<T> &a) {T x,y; cin >> x >> y; a.real(x),a.imag(y); return cin; }
typedef complex<double> P;//polar abs arg conj
#define X real()
#define Y imag()
#define pi acos(-1)

template<class T> inline constexpr T inf = numeric_limits<T>::max() / 2;
void solve(){
	P a = {1,0},b = {0,1};
	a.imag(1),a.real(0); //設值
	//  a = |a|e^xi = |a|(isinx + cosx)
	//a*b = |a||b|e^(x+y)i
	//polar(p,t) = 長度p且與+x夾t的向量
	a *= polar(1.0,pi/2); //旋轉 pi/2 rad
	auto prd = (conj(a)*b).X;// a dot b
	auto crs = (conj(a)*b).Y;// a cross b
	auto dis = abs(a-b); // |a-b|
	auto theta = arg(a); // 輻角 (a 跟 +x 夾角)
}