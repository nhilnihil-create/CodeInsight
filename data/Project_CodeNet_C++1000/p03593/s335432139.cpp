#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

string S[110];
int cnt[26];
int main()
{
	int H, W;
	cin >> H >> W;
	for (int i = 0; i < H; i++) cin >> S[i];
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cnt[S[i][j] - 'a']++;
		}
	}
	//for (int i = 0; i < 26; i++) cout << char('a' + i) << " " << cnt[i] << endl;
	if (H % 2 == 0 && W % 2 == 0) {
		for (int i = 0; i < H / 2 * W / 2; i++) {
			for (int j = 0; j < 26; j++) {
				if (cnt[j] >= 4) {
					cnt[j] -= 4;
					break;
				}
			}
		}
		for (int i = 0; i < 26; i++) {
			if (cnt[i] > 0) {
				cout << "No" << endl;
				return 0;
			}
		}
	}

	else if (H % 2 == 1 && W % 2 == 1) {
		for (int i = 0; i < H / 2 * W / 2; i++) {
			for (int j = 0; j < 26; j++) {
				if (cnt[j] >= 4) {
					cnt[j] -= 4;
					break;
				}
			}
		}
		for (int i = 0; i < H / 2 + W / 2; i++) {
			for (int j = 0; j < 26; j++) {
				if (cnt[j] >= 2) {
					cnt[j] -= 2;
					break;
				}
			}
		}
		for (int i = 0; i < 26; i++) {
			if (cnt[i] >= 1) {
				cnt[i] -= 1;
				break;
			}
		}
		for (int i = 0; i < 26; i++) {
			if (cnt[i] > 0) {
				cout << "No" << endl;
				return 0;
			}
		}
	}

	else {
		for (int i = 0; i < H / 2 * W / 2; i++) {
			for (int j = 0; j < 26; j++) {
				if (cnt[j] >= 4) {
					cnt[j] -= 4;
					break;
				}
			}
		}
		int n;
		if (H % 2 == 0) n = H / 2;
		else n = W / 2;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 26; j++) {
				if (cnt[j] >= 2) {
					cnt[j] -= 2;
					break;
				}
			}
		}
		for (int i = 0; i < 26; i++) {
			if (cnt[i] > 0) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}
