#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

#define REP(i,n) for(int i=0;(i)<(n);(i)++)
#define ll long long

int main() {
	int H, W;
	string s[30][30];

	cin >> H >> W;

	REP(i, H) {
		REP(j, W) {
			cin >> s[i][j];
		}
	}
	
	REP(i, H) {
		REP(j, W) {
			if (s[i][j] == "snuke") {
				cout << (char)('A' + j) << i + 1 << endl;
				return 0;
			}
		}
	}

	
	return 0;
}