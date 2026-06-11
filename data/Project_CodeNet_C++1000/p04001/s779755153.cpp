#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<18;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	ll ans = 0;
	cin >> s;
	int n = s.size();
	for(int i = 0; i < n; i++) {
		ll sum = 0;
		for(int j = i; j < n; j++) {
			sum = 10*sum + (s[j] - '0');
			ans += sum<<(n-1 - (j-i) - (i!=0) - (j+1!=n));
		}
	}
	cout << ans;
}
