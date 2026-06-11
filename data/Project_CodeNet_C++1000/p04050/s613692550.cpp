#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#define priority_queue __gnu_pbds::priority_queue
typedef long long LL;
typedef long double LD;
typedef unsigned long long ul;
#define ri register int
#define pb push_back
#define fi first
#define se second
#define mid ((l + r) >> 1)
#define ls (i << 1)
#define rs (i << 1 | 1)
#define enum(i, j, k) for(int i = j; i <= k; i ++)
#define FO(x) { freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout); }
using namespace std;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
typedef vector<int> vi;
#define ae(x) for(node *p = h[x]; p; p = p->nxt)
#define G \
	struct node { int v; node *nxt; } e[maxm], *h[maxn]; int z;\
	void adde(int u, int v) { e[++z].v = v; e[z].nxt = h[u]; h[u] = &e[z]; }\
	void addrev(int u, int v) { adde(u, v); adde(v, u); }
#define W \
	struct node { int v, w; node *nxt; } e[maxm], *h[maxn]; int z;\
	void adde(int u, int v, int w) { e[++z].v = v; e[z].w = w; e[z].nxt = h[u]; h[u] = &e[z]; }\
	void addrev(int u, int v, int w) { adde(u, v, w); adde(v, u, w); }
inline int _() // ret >= 0
{
	int ret = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	do { ret = ret * 10 + ch - '0'; ch = getchar(); } while('0' <= ch && ch <= '9');
	return ret;
}
inline void _(int x) // x >= 0
{
	if(x < 10) { putchar(x + '0'); return ; }
	_(x / 10); putchar(x % 10 + '0');
}
void What_are_you_doing_at_the_end_of_the_world_Are_you_busy_Can_you_save_us()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(16);
}
/* Default Code Ends Here. */

int n, m;
vi ji, ou;
int main()
{
	What_are_you_doing_at_the_end_of_the_world_Are_you_busy_Can_you_save_us();
	
	cin >> n >> m;
	if(n == 1)
		return cout << "1\n1\n1\n", 0;
	if(m == 1)
		return cout << n << endl << 2 << endl << 1 << ' ' << n - 1 << endl, 0;
	int d;
	enum(i, 1, m)
	{
		cin >> d;
		if(d & 1)
			ji.pb(d);
		else
			ou.pb(d);
	}
	if(ji.size() > 2)
		return cout << "Impossible" << endl, 0;
	random_shuffle(ou.begin(), ou.end());
	vi v;
	if(!ji.empty())
		v.pb(ji[0]);
	for(int i : ou)
		v.pb(i);
	if(ji.size() >= 2)
		v.pb(ji[1]);
	for(int i : v)
		cout << i << ' ';
	cout << endl;
	int res = v.size();
	cout << (v[res - 1] != 1 ? res : res - 1) << endl;
	cout << v[0] + 1 << ' ';
	enum(i, 1, res - 2)
		cout << v[i] << ' ';
	if(res != 1 && v[res - 1] != 1)
		cout << v[res - 1] - 1 << endl;
//	if(ji.size() == 0)
//	{
//		for(int i : ou)
//			cout << i << ' ';
//		cout << endl;
//		
//		cout << 2 << endl;
//		cout << 1 << ' ' << n - 1 << endl;
//	}
//	else if(ji.size() == 1)
//	{
//		if(ou.size() == 0)
//			return cout << ji[0] << endl << 2 << endl << 1 << ' ' << n - 1 << endl, 0;
//		cout << ji[0] << ' ';
//		for(int i : ou)
//			cout << i << ' ';
//		cout << endl;
//		
//		cout << 1 << endl;
//		cout << n << endl;
//	}
//	else
//	{
//		
//		cout << ji[0] << ' ';
//		for(int i : ou)
//			cout << i << ' ';
//		cout << ji[1] << endl;
//		
//		vi ans;
//		ans.pb(ji[0] + 1);
//		for(int i : ou)
//			ans.pb(i);
//		if(ji[1] > 1)
//			ans.pb(ji[1] - 1);
//		
//		cout << ans.size() << endl;
//		for(int i : ans)
//			cout << i << ' ';
//		cout << endl;
//	}
	return 0;
}