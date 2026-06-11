#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, c, k;
	cin >> n >> c >> k;

	vector<int> t(n);
	for (int i = 0; i < n; i++)	{
		cin >> t[i];
	}
	sort(t.begin(), t.end());
	int timelim = 0;
	int kyakunum = 0;
	int busnum = 0;
	int i = 0;
	bool brkflg = false;
	for (int timee = 0; timee <= t[t.size() - 1] + k; timee++) {
		bool nottaflg = false;

		do {
			nottaflg = false;
			if (t[i] <= timee && kyakunum <= c) {
				if (kyakunum == 0) {
					timelim = t[i];
					busnum++;
				}
				kyakunum++;
				nottaflg = true;
				i++;
				if (i > t.size() - 1) { brkflg = true; break; }
			}

			if (kyakunum == c || timee == timelim + k) {

				kyakunum = 0;
				break;
			}
		} while (nottaflg == true);

		if (brkflg) { break; }
	}
	cout << busnum << endl;

	return 0;
}