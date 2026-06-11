#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 5050, mlg = 17, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
string s, t;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, x;
	cin >> n >> x;
	n = 2*n-1;
	if(x == 1 || x == n) return cout << "No", 0;
	set<int> a;
	cout << "Yes\n";
	for(int i = 1; i <= n; i++) if(abs(x-i) > 1) a.insert(i);
	for(int i = 0; i < n; i++) {
		if(abs((n/2)-i) < 2) cout << x + ((n/2)-i) << "\n";
		else {
			cout << *a.begin() << '\n';
			a.erase(a.begin());
		}
	}
	
}
