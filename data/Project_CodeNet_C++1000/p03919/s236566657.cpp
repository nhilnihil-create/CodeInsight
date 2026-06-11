#include <bits/stdc++.h>
using namespace std;

void loop(int h, int w) {
	vector<vector<string>> s(h, vector<string>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> s.at(i).at(j);
			if (s.at(i).at(j) == "snuke") {
				cout << char('A' + j) << i + 1 << endl;
				return;
			}
		}
	}
}

int main()
{
	int h, w;
	cin >> h >> w;

	loop(h, w);
}