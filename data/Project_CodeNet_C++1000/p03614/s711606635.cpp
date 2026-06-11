#include"bits/stdc++.h"
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define INF 1e+9


int main() {
	pair<int, char> p[100001];
	int n,a;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (a == i) p[i] = make_pair(a,'x');
		else p[i] = make_pair(a, 'o');
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (p[i].second == 'x') {
			if (p[i + 1].second == 'x') {
				p[i + 1].second = 'o';
				ans++;
			}
			else {
				ans++;
			}
		}
	}

	cout << ans << endl;

	return 0;
}