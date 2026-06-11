#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	
	int n, a[100], sum = 0, med;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	for(int i = 0; i < n; i++) sum += a[i];
	float m = (float) sum / n;
	med = round(m);

	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans += (med - a[i]) * (med - a[i]);
	}
	
	cout << ans << endl;
	return 0;
}