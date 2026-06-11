#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll x, a, b;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> x >> a >> b;
	if (a >= b) cout << "delicious";
	else if (b - a <= x) cout << "safe";
	else cout << "dangerous";
}
