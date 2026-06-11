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
#include<map>
using namespace std;

#define int long long
#define REP(i,n) for(int i=0;(i)<(n);(i)++)
#define ll long long

map<pair<int,int>, int> mp;

signed main() {
	int H, W, N;
	cin >> H >> W >> N;

	int a, b;
	pair<int, int> p;
	REP(i, N) {
		cin >> a >> b;

		for (int i = -1;i <= 1;i++) {
			for (int j = -1;j <= 1;j++) {
				p.first = a + i;
				p.second = b + j;
				if (p.first<2 || p.first > H - 1 || p.second < 2 || p.second > W - 1) continue;
				mp[p]++;
			}
		}

	}

	/*
	for (int i = 1;i <= H;i++) {
		for (int j = 1;j <= W;j++) {
			pair<int, int> yx;
			yx.first = i; yx.second = j;
			cout << mp[yx] << " ";
		}
		cout << endl;
	}
	*/


	ll ans[10];
	ans[0] = (H - 2)*(W - 2);
	for (int i = 1;i <= 9;i++) {
		ans[i] = 0;
		for (auto m : mp) {
			if (m.second == i) ans[i]++;
		}

		ans[0] -= ans[i];
	}

	REP(i, 10) cout << ans[i] << endl;


	return 0;
}