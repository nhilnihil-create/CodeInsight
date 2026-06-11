#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int w, a, b; cin >> w >> a >> b;
	if(b+w < a) cout << a-b-w << '\n';
	else if(a+w < b) cout << b-a-w << '\n';
	else cout << 0 << '\n';
	return 0;
}