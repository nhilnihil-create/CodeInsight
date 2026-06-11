#include <bits/stdc++.h>
using namespace std;

int main(){
#ifdef _DEBUG
	freopen("in" , "r", stdin );
	freopen("out", "w", stdout);
#endif
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k, x, y; cin >> n >> k >> x >> y;
	if(n <= k) cout << n * x << '\n';
	else cout << k * x + (n - k) * y << '\n';
}
