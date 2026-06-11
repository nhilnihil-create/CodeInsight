#include <bits/stdc++.h>
using namespace std;

int main(){
#ifdef _DEBUG
	freopen("in" , "r", stdin );
	freopen("out", "w", stdout);
#endif
	ios::sync_with_stdio(0); cin.tie(0);
	double a, b, c; cin >> a >> b >> c;
	cout << (int)((a + b) / 2.0 * c) << '\n';
}
