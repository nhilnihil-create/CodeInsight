#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<string> > S(H, vector<string>(W));
	string ans;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> S[i][j];
			if (S[i][j] == "snuke") {
				char ch = 'A'+j;
				ans = ch+to_string(i+1);
			}
		}
	}

	cout << ans << endl;

}