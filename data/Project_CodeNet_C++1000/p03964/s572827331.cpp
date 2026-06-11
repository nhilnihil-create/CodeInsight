#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main(){
#ifdef _DEBUG
	freopen("in" , "r", stdin );
	freopen("out", "w", stdout);
#endif
	ios::sync_with_stdio(0); cin.tie(0);
	ull a = 1, b = 1;
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		ull x, y; cin >> x >> y;
		ull l = 1, r = 1e19, s = 1;
		while(l <= r){
			ull m = (l + r) / 2;
			if(x >= (a + m - 1) / m && y >= (b + m - 1) / m){
				s = m;
				r = m - 1;
			} else l = m + 1;
		}
		a = x * s; b = y * s;
	}
	cout << a + b << '\n';
}
