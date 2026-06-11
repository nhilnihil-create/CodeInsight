#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1e9+7;
using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;
	int a, eve = 0, add = 0;
	rep(i,n) {
		cin >> a;
		if (a % 2 == 0) eve++;
		else add++;
		if (add >= 2) {
			add -= 2;
			eve++;
		}
		while (eve >= 2) eve--;
	}
	if (add == 0 && eve == 1) cout << "YES";
	else cout << "NO";
	return 0;
}
