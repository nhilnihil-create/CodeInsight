#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define dprint(Exp,...) if(Exp){fprintf(stderr, __VA_ARGS__);}
#define printe(...) fprintf(stderr, __VA_ARGS__);
#define PrtExp(_Exp)  cerr<< #_Exp <<" = "<< (_Exp)
#define PrtExpN(_Exp)  cerr<< #_Exp <<" = "<< (_Exp) <<"\n"

#define SINT(n) scanf("%d",&n)
#define SINT2(n,m) scanf("%d %d",&n,&m)
#define SINT3(n,m,o) scanf("%d %d %d",&n,&m,&o)
#define SINT4(n,m,o,p) scanf("%d %d %d %d",&n,&m,&o,&p)
#define SINT5(n,m,o,p,q) scanf("%d %d %d %d %d",&n,&m,&o,&p,&q)
#define SLL(n) scanf("%lld",&n)
#define SLL2(n,m) scanf("%lld %lld",&n,&m)
#define SLL3(n,m,o) scanf("%lld %lld %lld",&n,&m,&o)
#define SST(s) scanf("%s",s)
#define SCH(c) scanf("%c",&c)

#define GC() getchar()

#define PINT(n) printf("%d",(int)(n))
#define PINT2(n,m) printf("%d %d",(int)(n),(int)(m))
#define PINT3(n,m,l) printf("%d %d %d",(int)(n),(int)(m),(int)(l))
#define PLL(n) printf("%lld",(long long)(n))
#define PST(s) printf("%s",(s))
#define PCH(s) printf("%c",(s))

#define PINTN(n) printf("%d\n",(int)(n))
#define PINT2N(n,m) printf("%d %d\n",(int)(n),(int)(m))
#define PINT3N(n,m,l) printf("%d %d %d\n",(int)(n),(int)(m),(int)(l))
#define PLLN(n) printf("%lld\n",(long long)(n))
#define PSTN(s) printf("%s\n",(s))
#define PCHN(s) printf("%c\n",(s))

#define PSP() printf(" ")
#define PN() printf("\n")

#define PC(c) putchar(c)
#define CSP (' ')
#define SN ("\n")

#define rep(i,a) for(int i=0;i<a;i++)
#define reP(i,a) for(int i=0;i<=a;i++)
#define Rep(i,a) for(int i=a-1;i>=0;i--)
#define ReP(i,a) for(int i=a;i>=0;i--)

#define rEp(i,a) for(i=0;i<a;i++)
#define rEP(i,a) for(i=0;i<=a;i++)
#define REp(i,a) for(i=a-1;i>=0;i--)
#define REP(i,a) for(i=a;i>=0;i--)

#define repft(i,a,b) for(int i=a;i<b;i++)
#define repfT(i,a,b) for(int i=a;i<=b;i++)
#define Repft(i,a,b) for(int i=a-1;i>=b;i--)
#define RepfT(i,a,b) for(int i=a;i>=b;i--)

#define foreach(a,it) for(auto it = a.begin(); it != a.end(); ++it)

#define FILL(a,v) fill(begin(a),end(a), v)
#define FILL0(a) memset(a,0,sizeof(a))
#define FILL1(a) memset(a,-1,sizeof(a))

typedef long long ll;

typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll>   Pll;


const int INF = 0x2aaaaaaa; // 715,827,882
const ll INFLL = 0x1f1f1f1f1f1f1f1fLL;//2,242,545,357,980,376,863

template <class A, class B> inline ostream& operator<<(ostream& st, const pair<A, B>& P) { return st << "(" << P.first << "," << P.second << ")"; };
template <class A, class B> inline pair<A, B> operator+(const pair<A, B>& P, const pair<A, B>& Q) { return pair<A, B>(P.first + Q.first, P.second + Q.second); };
template <class A, class B> inline pair<A, B> operator-(const pair<A, B>& P, const pair<A, B>& Q) { return pair<A, B>(P.first - Q.first, P.second - Q.second); };

#define fs  first
#define sc  second


int bitCount(int bits) {
	bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);    //  2bitごとに計算
	bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);    //  4bitごとに計算
	bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);    //  8bitごとに計算
	bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);    //  16ビットごとに計算   
	return (bits & 0x0000ffff) + (bits >> 16);    //  32ビット分を計算   
}

int h, w, d;


int m[512][512] = { {} };
bool f[512][512] = {};

bool isP(int i) {
	return i == 1 ||
		i == 2 ||
		i == 4 ||
		i == 8;
}


	
int main() {

	cin >> h >> w >> d;
	

	if (d % 2 == 1) {
		rep(i, h){
			rep(j, w) {
				cout << (((i + j) % 2 == 1) ? 'R' : 'Y');
			}
			cout << endl;
		}
		cout << endl; return 0;
	}


	vector<Pi> D;


	rep(x, d / 2)repft(y, 1 - d / 2, d / 2) {
		if (x + abs(y) >= d / 2)continue;
		D.push_back({ y,x });
		D.push_back({y,-x-1});
	}
	sort(D.begin(), D.end());
	//for (auto p : D)cout << p<<endl;


	rep(i, h)rep(j, w) {
		int y = i*d;
		int x = j*d;
		if (x > w * 3)continue;
		if (y > h * 3)continue;

		for (auto p : D) {
			int X = x + p.sc;
			int Y = y + p.fs;
			if (X < 0)continue;
			if (Y < 0)continue;
			if (X >= w)continue;
			if (Y >= h)continue;
			m[Y][X] = ((i+j)%2==0?0:1);
		}
		for (auto p : D) {
			int X = x + p.sc + d / 2;
			int Y = y + p.fs + d / 2;
			if (X < 0)continue;
			if (Y < 0)continue;
			if (X >= w)continue;
			if (Y >= h)continue;
			m[Y][X] = ((i + j) % 2 == 0 ? 2 : 3);
		}
	}

	/*
	for (int i = 0; i < h; i += d) {
		for (int j = 0; j < w; j += d) {
			int c = 0;
		}
	}
	*/


	

	char c[5] = "RGYB";
	rep(i, h) {
		rep(j, w) {
			cout << c[m[i][j]];// << " ";
			//cout << m[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	

	return 0;
}