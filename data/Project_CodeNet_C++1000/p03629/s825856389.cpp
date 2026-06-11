#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>

using namespace std;
typedef long long ll;

int main() {
	string A; cin >> A;

	for (int i = 0; i < 26; i++) {
		char a = 'a' + i;
		A.push_back(a);
	}
	int N = A.size();
	int INF = N * 2;
	
	int* dp = new int[N];
	int buf[26];
	for (int i = 0; i < N; i++) {
		int k = A[i] - 'a';
		dp[i] = INF;
		if (i + 26 >= N) { dp[i] = 0; buf[i + 26 - N] = i; }
	}
	for (int i = N - 27; i >= 0; i--) {
		int k = A[i] - 'a';

		for (int j = 0; j < 26; j++) {
			dp[i] = min(dp[i], dp[buf[j]] + 1);
		}
		buf[k] = i;
	}

	int n = INF;
	int M = INF;
	
	for (int i = 0; i < 26; i++) {
		if (dp[buf[i]] < M) {
			M = dp[buf[i]];
			n = buf[i];
		}
		buf[i] = 0;
	}

	while (1) {
		cout << A[n];
		if (M == 0) { break; }
		M--;

		for (int i = 0; i < 26; i++) {
			buf[i] = max(buf[i], n + 1);
			while (buf[i] < N && A[buf[i]] != 'a' + i) {
				buf[i]++;
			}
		}
		for (int i = 0; i < 26; i++) {
			if (dp[buf[i]] == M) {
				n = buf[i];
				break;
			}
		}
	}
	
	return 0;
}