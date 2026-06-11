#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;
using vll = vector<LL>;
using LD = long double;

#define ALL(v) v.begin(), v.end()
#define endl '\n'
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL); cerr.tie(NULL);
#define REP(i , n) for(int i =0 ; i < n ;i++)
#define REPN(i , n) for(int i = 1; i <= n ; i++)
#define cot(x) cerr << #x << " " << x << " ";
#define cotd(x) cerr << #x << " " << x << endl;
#define her 	cerr << " here \n"; 
#define pp push_back
#define fi first 
#define se second
#define un(x) x.erase(unique(ALL(x)), x.end())

template<typename T > void check(T & a, const T & b) { if (a >= b) { a %= b; } }
template<typename T>T gcd(T u, T v) { if (u == v)return u; if (u == 0)return v; if (v == 0)return u; if (~u & 1) { if (v & 1) return gcd(u >> 1, v); else return gcd(u >> 1, v >> 1) << 1; }if (~v & 1)return gcd(u, v >> 1); if (u > v)return gcd((u - v) >> 1, v); return gcd((v - u) >> 1, u); }
LL mulmod(LL a, LL b, const LL & m) { LL q = (LL)(((LD)a*(LD)b) / (LD)m); LL r = a*b - q*m; if (r>m)r %= m; if (r<0)r += m; return r; }
template <typename T, typename S>T expo(T e, S n) { T x = 1, p = e; while (n) { if (n & 1)x = x*p; p = p*p; n >>= 1; }return x; }
template <typename T>T powerL(T e, T n, const T & m) { T x = 1, p = e; while (n) { if (n & 1)x = mulmod(x, p, m); p = mulmod(p, p, m); n >>= 1; }return x; }

const int N = (int)1e5 + 10; 
int n, m, col[N];
vector<vi> g; 

int dfs(int u , int & ans){
	int nodes = 1; 
	for(auto & v : g[u]){
		if(!col[v]){
			col[v] = -col[u]; 
			nodes += dfs(v, ans);
		}
		else if(col[v] == col[u])
			ans = false; 
	}
	return nodes; 
}

int main(){
	SYNC; 
	cin >> n >> m; 
	g.resize(n + 1);

	REP(i , m){
		int u , v; cin >> u >> v; 
		u--; v--; 
		g[u].pp(v); g[v].pp(u); 
	}

	LL ans = 0; int leaf = 0, x = 0, y = 0;

	for(int i = 0; i < n; i++){
		if(!col[i]){
			col[i] = 1;
			int bi = 1; 
			int no = dfs(i , bi); 
			if(no == 1)leaf++; 
			else if(bi)x++; 
			else y++; 
		}
	}

	ans = ( 2 * leaf * 1LL * n) - (leaf * 1LL * leaf); 
	ans += (2 * x * 1LL * x) + (2 * x * 1LL * y) + ( y * 1LL * y ); 	
	cout << ans << endl; 

	return 0; 
}