#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

const ll P = 1000000007;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	
	ll n, m;
	cin >> n >> m;
	if(abs(n - m) > 1) {
		cout << 0 << endl;
		return 0;
	}
	
	ll ans = 1;
	if(n == m) {
		for(int i = 1; i <= n; i++) ans = ((ans % P) * (i % P) % P);
		ans = (ans * ans) % P;
		ans = (ans * 2) % P;
	} else {
		if(m < n) swap(n, m); 
		for(int i = 1; i <= n; i++) ans = ((ans % P) * (i % P) % P);	
		ans = (((ans * ans) % P) * m) % P;
	}
	
	cout << ans << endl;
}