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
	
	vector<int> a(n);
	for(int i=0; i<n; ++i) cin >> a[i];

	vector<int> b = a;
	sort(all(b));
	for(int &x : a) x = lower_bound(all(b), x) - b.begin();
	
	int res = 0;
	for(int i=0; i<n; ++i) res += (a[i] % 2 != i % 2);
	res /= 2;

	cout << res << "\n";

	return 0;
}