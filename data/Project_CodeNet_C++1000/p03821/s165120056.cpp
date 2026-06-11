#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define all(x) (x).begin(), (x).end()
#define fap(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << "\n"
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int inf = 0x3f3f3f3f;
const ll INF = 2e18;

int main() {
	FastIO;

	int n;
	cin >> n;

	vector<ll> a(n), b(n);
	for(int i=0; i<n; ++i) cin >> a[i] >> b[i];

	ll res = 0;
	for(int i=n-1; i>=0; --i) {
		a[i] += res;
		if(a[i] % b[i]) {
			ll rem = b[i] - a[i] % b[i];
			res += rem;
		}
	}

	cout << res << "\n";
	
	return 0;
}