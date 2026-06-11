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

string s;
int n;
vector<int> v;

const int M = 200000 / 26 + 1;
int L;
string ans;
bool tr[M][26][26];
bool vis[M][26];
bool dfs(int i, int c) {
	if(i == L) { return true; }
	if(exchange(vis[i][c], true)) { return false; }
	inc(d, 26) {
		if(tr[i][c][d] && dfs(i + 1, d)) {
			ans += ('a' + d);
			return true;
		}
	}
	return false;
}

int main() {
	cin >> s;
	n = s.size();
	
	int b[26], c = 0;
	inc(j, 26) { b[j] = 0; }
	v.PB(0);
	inc(i, n) {
		if(setmax(b[s[i] - 'a'], 1)) { c++; }
		if(c == 26) {
			v.PB(i + 1);
			inc(j, 26) { b[j] = 0; }
			c = 0;
		}
	}
	v.PB(n);
	
	L = v.size() - 1;
	inc(i,  L) {
	inc(j, 26) {
	inc(k, 26) {
		tr[i][j][k] = true;
	}
	}
	}
	
	inc(i, L) {
		bool b[26];
		inc(j, 26) { b[j] = true; }
		if(i != L - 1) {
			incID(j, v[i], v[i + 1]) {
				inc(k, 26) { tr[i + 1][k][s[j] - 'a'] &= b[k]; }
				b[s[j] - 'a'] = false;
			}
		} else {
			incID(j, v[i], v[i + 1]) {
				inc(k, 26) { tr[i + 0][k][s[j] - 'a'] = false; }
			}
		}
	}
	
	dfs(0, 0);
	reverse(ALL(ans));
	
	cout << ans << endl;
	
	return 0;
}
