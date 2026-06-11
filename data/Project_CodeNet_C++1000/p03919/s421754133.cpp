#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<utility>
#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)
#define MOD 1000000007
using namespace std;

int main(void) {
	int h, w;
	char moji[27][27][6];
	char alfa;
	cin >> h >> w;
	FOR(i, 1, h) {
		FOR(t, 1, w) {
			cin >> moji[i][t];
		}
	}
	FOR(i, 1, h) {
		FOR(t, 1, w) {
			if (strcmp(moji[i][t], "snuke")==0) {
				alfa = 'A' + t - 1;
				cout << alfa << i << endl;
			}
		}
	}
	return 0;
}