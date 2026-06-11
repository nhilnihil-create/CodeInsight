#include <bits/stdc++.h>
using namespace std;

int main() {
	string a,b,c; cin >> a >> b >> c;
	bool ok = true;
	if(a[a.size()-1]!=b[0]) ok = false;
	if(b[b.size()-1]!=c[0]) ok = false;
	if(ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}