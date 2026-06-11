#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int n, a[100000];

int main(){
	//IO("input.txt", "output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	long long sum = 0, mn = 0;
	for(int i = 0; i < n; i++){
		sum += a[i];
		if(i % 2 == 0 && sum <= 0) mn += 1 - sum, sum = 1;
		else if(i % 2 == 1 && sum >= 0) mn += 1 + sum, sum = -1;
	}
	sum = 0;
	long long cnt = 0;
	for(int i = 0; i < n; i++){
		sum += a[i];
		if(i % 2 == 0 && sum >= 0) cnt += 1 + sum, sum = -1;
		else if(i % 2 == 1 && sum <= 0) cnt += 1 - sum, sum = 1;
	}
	mn = min(mn, cnt);
	cout << mn << "\n";
	return 0;
}