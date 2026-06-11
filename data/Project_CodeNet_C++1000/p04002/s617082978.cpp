#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include<cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<utility>
#include <vector>

#define ll long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define FORR(i,a,b) for(int i=(a);i>=(b);--i)
#define REPR(i,n)   FORR(i,n,0)

using namespace std;

int main() {
	ll H, W, N, a, b;
	ll ans[10] = { 0 };
	map<int, set<int>> mp;

	cin >> H >> W >> N;
	ans[0] = (H - 2)*(W - 2);
	REP(i, N) {
		cin >> a >> b;
		int A[5][5] = { 0 };
		FOR(j, a - 2, a + 3) {
			FOR(k, b - 2, b + 3) {
				if (mp[j].count(k)) {
					A[j - a + 2][k - b + 2] = 1;
				}
			}
		}


		
		REP(j, 3) {
			REP(k, 3) {
				int cnt = 0;
				REP(l, 9) {
					if (A[j + l % 3][k + l / 3] == 1) {
						cnt++;
					}
				}
				if (j + a - 2 < 1 || k + b - 2 < 1 || j + a  > H || k + b  > W) {
					continue;
				}
				ans[cnt + 1]++;
				ans[cnt]--;
			}
		}
		
		mp[a].insert(b);
	}


	REP(i, 10) {
		cout << ans[i] << endl;
	}

	return 0;
}