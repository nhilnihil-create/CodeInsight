#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()

int n, l;
vector <string> s;
int32_t main() {
	cin >> n >> l;
	for(int i = 0; i < n; ++i) {
		string a; cin >> a;
		s.pb(a);
	}
	sort(all(s));
	for(auto it:s) cout << it;
}
