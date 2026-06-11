/* 
	Author: ankrypt
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define MOD 1000000007
#define ll long long int
#define u64 unsigned long long int
#define ff first
#define ss second
#define all(x) x.begin(), x.end() 
#define ub upper_bound
#define lb lower_bound
#define MAX_INT 105
#define fi(a, b, c, d) for(int a = b; i < c; i += d)
#define fl(a, b, c, d) for(ll a = b; i < c; i += d)
#define quit exit(0)

ll N, M, A, B, C;
ll arr[MAX_INT], arr1[MAX_INT], data[MAX_INT];
map<ll, ll> cache[5];
vector<ll> V;
set<ll> S;

int main() {
	scanf("%lld %lld", &N, &M);
	for(int i = 1; i <= N; i++) {
		scanf("%lld %lld", &arr[i], &arr1[i]);
	}
	ll X = 0;
	cache[0][0] = 0;
	for(int i = 1; i <= N; i++) {
		ll Y = X;
		X ^= 1;
		cache[X].clear();
		for(auto x: cache[Y]) {
			cache[X][x.ff] = max(cache[X][x.ff], x.ss);
			if(x.ff + arr[i] <= M) {
				cache[X][x.ff + arr[i]] = max(cache[X][x.ff + arr[i]], x.ss + arr1[i]);
			}
		}
	}
	ll ans = 0;
	for(auto x: cache[X]) {
		ans = max(ans, x.ss);
	}
	printf("%lld\n", ans);

	return 0;
}
/*
	Powered by Buggy Plugin
*/


