#include <bits/stdc++.h>
using namespace std;

#define MAXK 10000

int main() {
	int K, T;
	int day[MAXK];
	vector<pair<int, int>> C;  // cake count, cake id
	cin >> K >> T;
	bool algflg = false;
	for (int i = 0; i < T; i++) {
		int a;
		cin >> a;
		algflg = algflg || a * 2 > K;
		C.push_back(make_pair(a, i));
	}
    if (!algflg) {
        cout << 0 << endl;
        return 0;
    }
	sort(C.begin(), C.end());
	for (int i = 0; i < K; i += 2) {
		auto c = C.back();
		C.pop_back();
		day[i] = c.second;
		c.first--;
		if (c.first > 0) {
			C.push_back(c);
		}
	}
	for (int i = (K % 2 == 0 ? K - 1 : K - 2); i >= 0; i -= 2) {
		auto c = C.back();
		C.pop_back();
		day[i] = c.second;
		c.first--;
		if (c.first > 0) {
			C.push_back(c);
		}
	}
	int ans = 0;
	for (int i = 1; i < K; i++)
		if (day[i] == day[i - 1]) ans++;
	cout << ans << endl;
	return 0;
}