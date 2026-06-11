#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = n; i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
	int a, b, c;
	cin >>a >> b >> c;
	bool ok = false;
	if (a == 1) ok = true;
	for (int i = 1; i < b; i++)
	{
		int p = i * a;
		if (p % b == c) ok = true; 
	}
	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}