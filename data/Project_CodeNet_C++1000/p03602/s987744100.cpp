#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<iterator>
#include<complex>
#include<stack>
#include "stdio.h"
using namespace std;

#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)

using ll = long long;
using Pii = pair<int, int>;

const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const long long mod_const = 1e9+7;

int dy[] = { 0, 0, 1, -1, 0 };
int dx[] = { 1, -1, 0, 0, 0 };

using MIte = multimap<ll, ll, greater<ll> >::iterator;

ll aaN[300][300];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// long long?
	int N;
	cin >> N;

	ll dist = 0;
	ll rem = 0;
	rep(i, N) {
		rep(j, N) {
			cin >> aaN[i][j];
			
		}
	}

	for (int i = 0; i != N; ++i) {
		for (int j = i; j != N; ++j) {
			if (i == j) continue;
//			dist += aaN[i][j];
			bool add = true;
			for (int k = 0; k != N; ++k) {
				if (k != i && k != j) {
					if (aaN[i][j] == aaN[i][k] + aaN[k][j]) {
						add = false;
						rem += aaN[i][k] + aaN[k][j];
					}
					else if (aaN[i][j] > aaN[i][k] + aaN[k][j]) {
						cout << "-1" << endl;
						return 0;
					}
				}
			}
			if (add) {
				dist += aaN[i][j];
			}
		}
	}

	cout << dist << endl;

	return 0;
}