#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, l, t, nxt;
vector<int> arv;
int main() {
	cin >> n >> l >> t;
	for (int i = 0; i < n; i++) {
		int x, w;
		cin >> x >> w;
		if (w == 1) {
			arv.push_back((x + t) % l);
			if (l - x <= t)
				nxt += (t - (l - x)) / l + 1;
			nxt %= n;
		}
		else {
			arv.push_back(((x - t) % l + l) % l);
			if (x < t) 
				nxt -= (t - (x + 1)) / l + 1;
			nxt %= n;
		}
	}
	nxt = ((nxt % n) + n) % n;
	sort(arv.begin(), arv.end());
	for (int i = nxt; i < arv.size(); i++)
		cout << arv[i] << "\n";
	for (int i = 0; i < nxt; i++)
		cout << arv[i] << "\n";
	return 0;
}
