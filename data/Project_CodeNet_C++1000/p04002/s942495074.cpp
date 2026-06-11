#include<iostream>
#include<cstring>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
//int dp[1001][1001][1001];

//long long int DP(int n, int m, int l);
//int dp2[1001][1001][1001];

//long long int DP2(int n, int m, int l);
//long long int MOD = 1000000007;
int main() {

	//F
	/*memset(dp, -1, sizeof(dp));
	int n, m, l;
	cin >> n >> m >> l;
	cout << DP(n, m, l) << endl;
	return 0;*/

	//D
	vector<pair <long long int, long long int>> pairs;
	long long int h, w;
	int a, b;
	cin >> h >> w;
	long long int counter[10];
	counter[0] = (h - 2) * (w - 2);
	int i, j, k;
	for (i = 1; i < 10; i++)counter[i] = 0;
	int n;
	cin >> n;
	//int a, b;
	//cout << "a";
	for (i = 0; i < n; i++) {
		cin >> a >> b;
		for (j = max(a - 2, 1); j <= min(a, (int)(h-2)); j++) {
			for (k = max(b - 2, 1); k <= min(b, (int)(w - 2)); k++) {
				pairs.push_back(pair<long long int, long long int>(j, k));
			}
				
		}
	}
	//cout << "i";
	sort(pairs.begin(), pairs.end());
	if (pairs.size() == 0) {
		for (i = 0; i < 10; i++) {
			cout << counter[i] << endl;
		}
		return 0;

	}
	//cout << "u";
	//cout << pairs[0].first << ' ' << pairs[0].second << endl;
	pair<long long int, long long int>pp = pairs[0];
	//cout << "e";
	int c = 1;
	for (i = 1; i < pairs.size(); i++) {
		if (pairs[i] == pp) {
			c++;
		}
		else {
			counter[c]++;
			c = 1;
			pp = pairs[i];
		}
	}
	
	counter[c]++;
	for (i = 1; i < 10; i++) {
		counter[0] = counter[0] - counter[i];
	}
	for (i = 0; i < 10; i++) {
		cout << counter[i] << endl;
	}
	return 0;

	//C
	/*
	long long int sum = 0;
	string s;
	cin >> s;
	int i;
	int bin[10] = { 1,2,4,8,16,32,64,128,256,512 };
	int j;
	long long int k;
	for (i = 0; i < bin[s.size() - 1]; i++) {
		k = (s[0] - '0');
		for (j = 0; j < s.size() - 1; j++) {
			if ((i ^ bin[j]) == (i + bin[j])) {
				sum = sum + k;
				//cout << k << endl;
				k = (s[j + 1] - '0');
			}
			else {
				k = k * 10;
				k = k + (s[j + 1] - '0');
			}
		}
		sum = sum + k;
		//cout << k << endl;
	}
	cout << sum << endl;
	return 0;
	*/
}
/*long long int DP(int n, int m, int l) {

	if (dp[n][m][l] >= 0)return dp[n][m][l];
	int i;
	long long int d;
	if (n == 0) {
		d = 1;
		for (i = 0; i < m + l; i++) {
			d = (d * 3) % MOD;
		}
		dp[n][m][l] = d;
		return d;
	}
	else {
		d = DP(n - 1, m, l) + DP2(m, n - 1, l);
		d = d % MOD;
		d = d + DP2(l, n - 1, m);
		d = d % MOD;
		dp[n][m][l] = d;
		return d;
	}
}
long long int DP2(int n, int m, int l) {

	if (dp2[n][m][l] >= 0)return dp2[n][m][l];
	int i;
	long long int d;
	if (n == 0) {
		dp2[n][m][l] = 0;
		return 0;
	}
	else {
		d = DP(m, n-1, l) + DP2(n-1, m, l);
		d = d % MOD;
		d = d + DP2(l, m, n-1);
		d = d % MOD;
		dp2[n][m][l] = d;
		return d;
	}
}*/