///A drunk man will find his way home, but a drunk bird may get lost forever...
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
//template <typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tree<double, null_type, less_equal<double>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define int long long
typedef long long ll;
typedef double dd;
typedef long double ldd;
typedef pair <int, int> pii;
typedef pair <pii , int> ppii;
#define pb push_back
#define pf push_front
#define ppb pop_back()
#define ppf pop_front()
#define f first
#define s second
#define sz(x) (int)x.size()
#define smin(x , y) x = min(x , y)
#define smax(x , y) x = max(x , y)
#define mp make_pair
#define all(x) x.begin() , x.end()
#define debug(x) cerr<< #x << " = " << x << endl
#define ddebug(x, y) cerr<< #x << " = " << x  << ", " << #y << " = " << y << endl
#define uop(x, y) pii(min(x, y), max(x, y))
#define mem(a, b) memset(a, b, sizeof a)
#define sq(x) (x) * (x)
#define out return cout << -1 << endl, 0
const int mx = 1e5 + 10;
int x[mx], p[mx], d[mx], ans[mx];
bool mark[mx];
vector < int > v;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k, a;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x[i];
		p[i] = i;
	}
	for(int i = 0; i < n - 1; i++)
		d[i] = x[i + 1] - x[i];
	cin >> m >> k;
	while(m--){
		cin >> a;
		swap(p[a - 1] , p[a - 2]);
	}
	for(int i = 0; i < n; i++)
		if(!mark[i]){
			mark[i] = 1;
			v.pb(i);
			int u = p[i];
			while(u != i){
				v.pb(u);
				mark[u] = 1;
				u = p[u];
			}
			for(int j = 0; j < sz(v); j++)
				ans[v[j]] = v[(j + k) % sz(v)];
			v.clear();
		}
	int s = x[0];
	for(int i = 0; i < n; i++){
		cout << s << ".0" << "\n";
		s += d[ans[i]];
	}
	return 0;
}
