#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;
typedef pair<int, int> P;

int main()
{
	int N;
	string S[2];
	cin >> N >> S[0] >> S[1];
	string T[2];
	T[0].push_back(S[0][0]);
	T[1].push_back(S[1][0]);
	for (int j = 0; j < 2; j++) {
		for (int i = 1; i < S[0].size(); i++) {
			if (S[j][i] != S[j][i - 1]) {
				T[j].push_back(S[j][i]);
			}
		}
	}
	//cout << T[0] << endl << T[1] << endl;
	ll ans = 3;
	bool line = false;
	if (T[0][0] != T[1][0]) {
		ans *= 2;
		line = true;
	}
	for (int i = 1; i < T[0].size(); i++) {
		if (T[0][i] == T[1][i] && line) {
			line = false;
		}
		else if (T[0][i] != T[1][i] && line) {
			ans *= 3;
		}
		else {
			ans *= 2;
			if (T[0][i] != T[1][i]) {
				line = true;
			}
		}
		ans %= mod;
		//cout << ans << endl;
	}
	cout << ans % mod << endl;
}
