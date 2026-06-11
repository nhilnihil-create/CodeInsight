#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long dp[100][100];

long long solve2(vector<int>vec1, vector<int>vec2) {
	for (int i = 0; i <= vec1.size(); i++) { for (int j = 0; j <= vec2.size(); j++) dp[i][j] = 0; }
	dp[0][0] = 1;
	for (int i = 0; i < vec1.size(); i++) {
		for (int j = 0; j <= vec2.size(); j++) {
			dp[i + 1][j] += dp[i][j];
			for (int k = j; k < vec2.size(); k++) {
				if (vec1[i] == vec2[k]) dp[i + 1][k + 1] += dp[i][j];
				if (j == 0 && k == 0) break;
			}
		}
	}
	long long F = 0;
	for (int i = 1; i <= vec2.size(); i++) F += dp[vec1.size()][i];
	return F;
}

long long solve(vector<int>vec) {
	long long ret = 0;
	for (int i = 1; i < vec.size(); i++) {
		vector<int>vec1, vec2;
		for (int j = 0; j < i; j++) vec1.push_back(vec[j]);
		for (int j = i; j < vec.size(); j++) vec2.push_back(vec[j]);
		ret += solve2(vec1, vec2);
	}
	return ret;
}

vector<pair<long long, vector<int>>>vec;

void init() {
	for (int i = 1; i <= 40; i++) {
		vector<int>V;
		for (int j = 0; j < i; j++) V.push_back(j);
		long long ret = solve(V);
		vec.push_back(make_pair(ret, V));
	}
	for (int i = 1; i <= 55; i++) {
		for (int j = 0; j < 100; j++) {
			vector<int>V;
			for (int k = 0; k < i; k++) V.push_back(rand() % 2);
			long long ret = solve(V);
			vec.push_back(make_pair(ret, V));
		}
	}
	sort(vec.begin(), vec.end());
}

long long n;

int main() {
	init();
	cin >> n;
	int cnt = 0; vector<int>ans;
	while (n >= 1) {
		int pos = 0;
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i].first <= n) pos = i;
		}
		vector<int>G = vec[pos].second;
		for (int i = 0; i < G.size(); i++) ans.push_back(cnt * 2 + G[i] + 1);
		n -= vec[pos].first;
		cnt++;
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) { if (i)cout << " "; cout << ans[i]; } cout << endl;
	return 0;
}