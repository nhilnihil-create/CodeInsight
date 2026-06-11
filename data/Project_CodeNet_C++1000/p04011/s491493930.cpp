#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	
	int n, k, x, y;
	cin >> n >> k >> x >> y;
	
	ll res = 0;
	if(n <= k) res = n * x;
	else {
		res = k * x + (n - k) * y;
	}
	
	cout << res << endl;
	return 0;
}