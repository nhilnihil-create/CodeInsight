#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	vector<int> x(3);
	rep(i, 3) cin >> x.at(i);
	sort(x.begin(), x.end());
	cout << x[0] + x[1] << endl;
	return 0;
}
