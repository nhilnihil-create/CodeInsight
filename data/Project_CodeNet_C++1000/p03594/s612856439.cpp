#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxd = 4;
const string let = "RYGB";
const int Maxn = 505;

int n, m, d;
char B[Maxn][Maxn];

int main()
{
	scanf("%d %d %d", &n, &m, &d);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int d1 = i + j, d2 = i - j + m;
			int val1 = d1 / d % 2? 1: 0, val2 = d2 / d % 2? 2: 0;
			B[i][j] = let[val1 + val2];
		}
		B[i][m] = '\0';
		printf("%s\n", B[i]);
	}
	return 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			set <char> S;
			for (int k = 0; k <= d && k <= i; k++) {
				int l = d - k;
				if (j - l >= 0) S.insert(B[i - k][j - l]);
				if (j + l < m && k > 0) S.insert(B[i - k][j + l]);
			}
			int k = 0;
			while (k < Maxd && S.find(let[k]) != S.end()) k++;
			if (k >= Maxd) { printf("FAIL at %d %d\n", i, j); return 0; }
			else B[i][j] = let[k];
		}
	for (int i = 0; i < n; i++) {
		B[i][m] = '\0';
		printf("%s\n", B[i]);
	}
	return 0;
	int rad = (d + 1) / 2;
	int st = 0;
	for (int j = 0; j < m; j += rad) {
		st = (st + Maxd - 1) % Maxd;
		int cur = st;
		for (int i = 0; i < n; i += rad) {
			cur = (cur + 1) % Maxd;
			for (int l1 = 0; l1 < rad; l1++)
				for (int l2 = 0; l2 < rad; l2++)
					if (i + l1 < n && j + l2 < m)
						B[i + l1][j + l2] = let[cur];
		}
	}
	for (int i = 0; i < n; i++) {
		B[i][m] = '\0';
		printf("%s\n", B[i]);
	}
	return 0;
}