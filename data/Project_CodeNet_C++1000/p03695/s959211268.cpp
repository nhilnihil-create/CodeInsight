#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int>g(9,0);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x >= 3200)x = 3200;
		g.at(x / 400)++;
	}
	int mi = 0;
	int ma = 0;
	for (int i = 0; i < 8; i++)if (g.at(i) >= 1)mi++;
	ma = mi + g.at(8);
	mi = max(mi, 1);
	cout << mi << " " << ma << endl;
}