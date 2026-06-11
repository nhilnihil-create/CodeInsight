#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
//pro player move
#define int LL

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int> vi;

template<class T> inline T re(){
	T N = 0; char c = getchar(); bool neg = 0;
	for (; c < '0' || c > '9'; c = getchar()) neg |= c == '-';
	for (; c >= '0' && c <= '9'; c = getchar())
		N = (N<<3)+(N<<1) + c - '0';
	return neg ? -N : N;
}

const int mxsz = 1e5 + 3;
int n;
vi adj[mxsz];
int need[mxsz], a[mxsz];

inline void CANNOT(){
	puts("NO"); exit(0);
}
void dfs(int u, int prv = -1){
	int cur = 0, chld = 0;
	for (int nx : adj[u]){
		if (nx == prv) continue;
		dfs(nx, u);
		chld++;
		cur += need[nx];
		if (need[nx] > a[u]) CANNOT();
	}
//	cout << "WORK " << u << '\n';
	if (chld == 0){
		need[u] = a[u];
//		cout << need[u] << '\n' ;
		return;
	} else if (chld == 1){
		if (cur != a[u]) CANNOT();
		need[u] = cur;
		return;
	}
	int now = a[u];
	if (now > cur) CANNOT();
	int p = cur - now;
	int U = now - p;
	if (U < 0 || U > a[u]) CANNOT();
//	cout << now << ' ' << cur << ' ' <<  p << ' ' << U << '\n';
	need[u] = U;
//	cout << need[u] << '\n';
}
int32_t main(){
	n = re<int>();
	for (int i = 1; i <= n; i++){
		a[i] = re<int>();
	}
	for (int i = 1, x, y; i < n; i++){
		x = re<int>(); y = re<int>();
		adj[x].pb(y); adj[y].pb(x);
	}
	if (n == 1){
		if (a[1] == 0) puts("YES");
		else CANNOT();
		return 0;
	} else if (n == 2){
		if (a[1] == a[2]) puts("YES");
		else CANNOT();
		return 0;
	}
	int st = 1;
	while (adj[st].size() == 1) st++;
	dfs(st);
	if (need[st] == 0) puts("YES");
	else CANNOT();
	return 0;
}
