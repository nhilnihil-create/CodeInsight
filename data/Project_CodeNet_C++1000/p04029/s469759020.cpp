#include <bits/stdc++.h>
using namespace std;

int main(){
#ifdef _DEBUG
	freopen("in" , "r", stdin );
	freopen("out", "w", stdout);
#endif
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	cout << n * (n + 1) / 2 << ' ';
}
