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
#define UB upper_bound
#define LB lower_bound
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

int n, a[100];

bool ask(LL v) {
	string s;
	cout << "? " << v << endl;
	cin >> s;
	return (s == "Y");
}

void ans(LL v) {
	cout << "! " << v << endl;
	exit(0);
}

LL ex(LL x, LL y) {
	return (y == 0 ? 1 : x * ex(x, y - 1));
}

int main() {
	int e = -1;
	inc(i, 10) {
		if(! ask(ex(10, i))) { e = i; break; }
	}
	
	if(e == -1) {
		inc(i, 10) { 
			if(ask(2 * ex(10, i))) { ans(ex(10, i)); }
		}
	}
	
	LL L = ex(10, e - 1), H = ex(10, e);
	while(H - L > 1) {
		LL M = (L + H) / 2;
		(ask(M * 10) ? H : L) = M;
	}
	ans(H);
	
	return 0;
}
