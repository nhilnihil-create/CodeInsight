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

LL n, a[100000], ans[100001][3], INF = 1e15;
char op[100000];

int sg(int k) { return (k % 2 == 0 ? +1 : -1); }

int main() {
	cin >> n;
	inc(i, n) {
		if(i == 0) { op[0] = '+'; } else { cin >> op[i]; }
		cin >> a[i];
	}
	
	incII(i, 0, n) {
	inc(k, 3) {
		ans[i][k] = -INF;
	}
	}
	ans[0][0] = 0;
	inc(i, n) {
		if(op[i] == '+') {
			inc(k, 3) { ans[i + 1][k    ] = ans[i][k] + sg(k    ) * a[i]; }
		} else {
			inc(k, 2) { ans[i + 1][k + 1] = ans[i][k] + sg(k + 1) * a[i]; }
		}
		
		dec(k, 2) { setmax(ans[i + 1][k], ans[i + 1][k + 1]); }
	}
	
	cout << ans[n][0] << endl;
	
	return 0;
}
