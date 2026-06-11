#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)


// Write From This Line
int main()
{
	int n;
	cin >> n;
	vector<int> l(n), r(n);
	rep(i,n) cin >> l[i] >> r[i];
	ll ans = 0;
	rep(i,n){
		ans += r[i] - l[i] + 1;
	}
	cout << ans << endl;
}
