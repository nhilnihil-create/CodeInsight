#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;

void solve() {
	int n;
	cin >> n; 
	int arr[n];
	ll sum = 0;
	for(int i = 0; i < n; ++i) cin >> arr[i], sum += arr[i];
	int m; 
	cin >> m;
	for(int i = 0; i < m; ++i) {
		int pos, val;
		cin >> pos >> val;
		--pos;
		if(val > arr[pos]) cout << sum + (val - arr[pos]) << endl;
		else cout << sum - (arr[pos] - val) << endl;
		}
}

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(35);
	solve();
	return 0;
	}
