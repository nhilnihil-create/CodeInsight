#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;


void solve() {
	int n, x;
	cin >> n >> x;
	int arr[n];
	for(int i = 0; i < n; ++i) cin >> arr[i]; 
	sort(arr, arr + n);
	ll ans = 0;
	int i = n - 1; 
	while(x--) ans += arr[i--];
	cout << ans << endl;
}

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(35);
	solve();
	return 0;
	}
