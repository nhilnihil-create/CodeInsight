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
//const int mx = 1e5 + 10;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, ans = 0;
	string s, t;
	cin >> n >> s >> t;
	for(int i = 0; i < n; i++){
		bool b = 1;
		for(int j = 0; j <= i; j++)
			b &= (s[n - j - 1] == t[i - j]);
		if(b)
			smax(ans , i + 1);
	}
	cout << 2 * n - ans << endl;
	return 0;
}
