#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int>v(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	int r;
	cin >> r;
	while (r--) {
		int x, val;
		cin >> x >> val;
		cout << sum + val - v[x - 1] << endl;
	}
}