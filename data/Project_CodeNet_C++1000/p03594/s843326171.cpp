#include <bits/stdc++.h>
using namespace std;

typedef long long   signed int LL;
typedef long long unsigned int LU;

#define incID(i, l, r) for(int i = (l)    ; i <  (r); i++)
#define incII(i, l, r) for(int i = (l)    ; i <= (r); i++)
#define decID(i, l, r) for(int i = (r) - 1; i >= (l); i--)
#define decII(i, l, r) for(int i = (r)    ; i >= (l); i--)
#define  inc(i, n) incID(i, 0, n)
#define inc1(i, n) incII(i, 1, n)
#define  dec(i, n) decID(i, 0, n)
#define dec1(i, n) decII(i, 1, n)

#define inII(v, l, r) ((l) <= (v) && (v) <= (r))
#define inID(v, l, r) ((l) <= (v) && (v) <  (r))

#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define PQ priority_queue

#define  ALL(v)  v.begin(),  v.end()
#define RALL(v) v.rbegin(), v.rend()
#define  FOR(it, v) for(auto it =  v.begin(); it !=  v.end(); ++it)
#define RFOR(it, v) for(auto it = v.rbegin(); it != v.rend(); ++it)

template<typename T> bool   setmin(T & a, T b) { if(b <  a) { a = b; return true; } else { return false; } }
template<typename T> bool   setmax(T & a, T b) { if(b >  a) { a = b; return true; } else { return false; } }
template<typename T> bool setmineq(T & a, T b) { if(b <= a) { a = b; return true; } else { return false; } }
template<typename T> bool setmaxeq(T & a, T b) { if(b >= a) { a = b; return true; } else { return false; } }
template<typename T> T gcd(T a, T b) { return (b == 0 ? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

// ---- ----

int h, w, d;
int ans[500][500], z[1000][1000];
string s = "RYGB";
template<typename T> T setmod(T & x, T y) { return ((x %= y) += y) %= y; }

int main() {
	cin >> h >> w >> d;
	
	if(d % 2 != 0) {
		inc(i, h) {
		inc(j, w) {
			ans[i][j] = (i + j) % 2;
		}
		}
	} else {
		inc(i, d) {
		inc(j, d) {
			int I = i; if(d % 4 == 0) { I -= (i + 1) / (d / 2); }
			int J = j; if(d % 4 == 0) { J -= (j + 1) / (d / 2); }
			I %= 2;
			J %= 2;
			z[i][j] = I * 2 + J;
		}
		}
		
		inc(i, h) {
		inc(k, w) {
			int j = k + (i + k) % 2;
			int I = (i - j) / 2;
			int J = (i + j) / 2;
			setmod(I, d);
			setmod(J, d);
			ans[i][k] = z[I][J];
		}
		}
	}
	
	inc(i, h) {
	inc(j, w) {
		cout << s[ans[i][j]];
	} cout << "\n";
	}
	
	return 0;
}
