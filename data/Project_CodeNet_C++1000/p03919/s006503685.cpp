#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<iomanip>

using namespace std;

int main(void) {
	int h, w;
	cin >> h >> w;
	vector<vector<string>>s(h, vector<string>(w));
	char alpha[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ans;
	int ans_;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> s[i][j];
			if (s[i][j] == "snuke") {
				ans = alpha[j];
				ans_ = i+1;
			}
		}
	}
	cout << ans << ans_;
	return 0;
}