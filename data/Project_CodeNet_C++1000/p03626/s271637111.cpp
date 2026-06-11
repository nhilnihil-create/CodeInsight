#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	long long n, i, j, k, total, MOD = 1000000007, a, b;
	string s1, s2;
	cin >> n >> s1 >> s2;

	vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(3, vector<long long>(3, 0)));

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if ((i == j) && (s1[0] != s2[0])) continue;
			if ((i != j) && (s1[0] == s2[0])) continue;
			dp[0][i][j]++;
		}
	}

	for (k = 1; k < n; k++) {
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				if ((i == j) && (s1[k] != s2[k])) continue;
				if ((i != j) && (s1[k] == s2[k])) continue;
				
				for (a = 0; a < 3; a++) {
					for (b = 0; b < 3; b++) {
						if ((s1[k] == s1[k - 1]) && (a != i)) continue;
						if ((s1[k] != s1[k - 1]) && (a == i)) continue;
						if ((s2[k] == s2[k - 1]) && (b != j)) continue;
						if ((s2[k] != s2[k - 1]) && (b == j)) continue;

						dp[k][i][j] = (dp[k][i][j] + dp[k - 1][a][b]) % MOD;
					}
				}
			}
		}
	}


	total = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) total = (total + dp[n - 1][i][j]) % MOD;
	}
	cout << total << "\n";
	

	return 0;
}
