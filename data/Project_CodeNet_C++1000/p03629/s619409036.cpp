#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string S;
int dp[200000 + 10];
int nxt[200000 + 10][26];
char hukugen[200000 + 10];
int comefrom[200000 + 10];

int main() {
	cin >> S;

	for (int i = 0; i < 26; i++) {
		nxt[S.size()][i] = S.size();
	}
	for (int i = S.size() - 1; i >= 0; i--) {
		for (int j = 0; j < 26; j++) {
			if (j + 'a' == S[i])nxt[i][j] = i;
			else nxt[i][j] = nxt[i + 1][j];
		}
	}

	dp[S.size()] = 1;
	for (int i = S.size() - 1; i >= 0; i--) {
		int tmp = 1145141919;
		for (int j = 0; j < 26; j++) {
			if (nxt[i][j] == S.size()) {
				if (tmp > 1) {
					//辞書順対策
					tmp = 1;
					hukugen[i] = 'a' + j;
					comefrom[i] = S.size();
				}
			}
			else {
				if (tmp > dp[nxt[i][j] + 1] + 1) {
					tmp = dp[nxt[i][j] + 1] + 1;
					hukugen[i] = 'a' + j;
					comefrom[i] = nxt[i][j] + 1;
				}
			}
		}
		dp[i] = tmp;
	}
	int idx = 0;
	string ans = "";
	while (idx < S.size()) {
		ans += hukugen[idx];
		idx = comefrom[idx];
	}
	cout << ans << endl;
	return 0;
}