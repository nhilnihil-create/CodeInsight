#include <bits/stdc++.h>
using namespace std;

int main(){
#ifdef _DEBUG
	freopen("in" , "r", stdin );
	freopen("out", "w", stdout);
#endif
	ios::sync_with_stdio(0); cin.tie(0);
	int a, b, c; cin >> a >> b >> c;
	if(a + b == c || a + c == b || b + c == a) cout << "Yes\n";
	else cout << "No\n";
}
