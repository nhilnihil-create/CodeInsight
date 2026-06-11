#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;

ll find_power(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b & 1) (res *= a)%= mod;
		(a *= a) %= mod;
		b >>= 1;
		}
		return res%mod;
	}

void solve() {
	int n;
	cin >> n; 
	vector<int> arr(n + 1, 0);
	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		arr[x]++;
		}
		for(int i = 1; i <= n; ++i) {
			if(arr[i] % 2) {
				cout << 0 << endl;
				return;
				}
			}	
		int ans = n / 2;
		cout << find_power(2, ans) << endl;
}

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(35);
	solve();
	return 0;
	}
