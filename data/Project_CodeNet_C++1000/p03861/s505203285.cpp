// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long a, b, x;
	cin >> a >> b >> x;
	if(a==0) cout << b/x+1;
	else cout << b/x - (a-1)/x;
	return 0;
}
