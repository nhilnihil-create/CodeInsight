#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int f = 0, s = 0;
	int a, b, c; cin >> a >> b >> c;
	if(a == 5) ++f;
	if(b == 5) ++f;
	if(c == 5) ++f;
	if(a == 7) ++s;
	if(b == 7) ++s;
	if(c == 7) ++s;
	cout << (f == 2 && s == 1 ? "YES" : "NO") << '\n'; 
	return 0;
}