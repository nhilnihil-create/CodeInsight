//besmellah
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 58;
int a[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i] & 1;
	}
	if (n % 2 == 0) {
		if (sum % 2) cout << "First";
		else cout << "Second";
	}
	else {
		if (n == 1) cout << "Second";
		else if (sum % 2 == 0) {
//			vector <int> S;
//			for (int i = 0; i < n; i++) {
//				S.push_back(__builtin_ctz(a[i]));
//			}
//			sort(S.begin(), S.end());
//			if (S[0] == S.back()) cout << "Second";
			cout << "First";
		}
		else {
			vector <int> S;
			for (int i = 0; i < n; i++) {
				S.push_back(__builtin_ctz(a[i]));
			}
			sort(S.begin(), S.end());
			int t = 0;
			while (S[0] != S[1] && S[0] == 0) {
				int g = 0;
				for (int i = 0; i < n; i++) {
					if (__builtin_ctz(a[i]) == 0) {
						a[i]--;
					}
					g = __gcd(a[i], g);
				}
				int d = 0;
				S.clear();
				bool f = 0;
				for (int i = 0; i < n; i++) {
					a[i] /= g;
					d += a[i] & 1;
//					assert(a[i]);
					if (a[i])
						S.push_back(__builtin_ctz(a[i]));
					else f = 1;
				}
				sort(S.begin(), S.end());
				if (d % 2 && !f) t++;
				else break;
			}
			if (t % 2) cout << "First";
			else cout << "Second";
		}
	}
}
