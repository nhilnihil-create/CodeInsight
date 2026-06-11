
#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <cmath>   
#include<cctype>
#include<string>
#include<set>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include <deque>
#include <typeinfo>
#include <utility> 
#define all(x) (x).begin(),(x).end()
#define rep(i,m,n) for(int i = m;i < n;++i)
using namespace std;
using ll = long long;
using R = double;
const ll inf = 1LL << 50;
const ll MOD = 1e9 + 7;
struct edge { ll from; ll to; ll cost; };



ll n;
ll dist_1[305][305];
ll dist_2[305][305];
ll mincost[305];
bool used[305];


int main() {
	cin >> n;
	ll sum = 0;
	rep(i, 0, n)rep(j, 0, n) {
		ll x;
		cin >> x;
		dist_1[i][j] = x;
		dist_2[i][j] = x;
		if (i > j)sum += x;
	}

	rep(k, 0, n)rep(i, 0, n)rep(j, 0, n) {
		dist_1[i][j] = min(dist_1[i][j], dist_1[i][k] + dist_1[k][j]);
	}

	bool ok = 1;
	rep(i, 0, n)rep(j, 0, n) {
		if (dist_1[i][j] != dist_2[i][j])ok = 0;
	}

	if (!ok) {
		cout << "-1" << endl;
		exit(0);
	}

	rep(i, 0, n)rep(j, 0, n) {
		bool fl = 0;
		rep(k, 0, n) {
			if (i < j && k != i && k != j) {
				if (dist_1[i][j] >= dist_1[i][k] + dist_1[k][j] && fl == 0) {
					sum -= dist_1[i][j];
					fl = 1;
				}
			}
		}
	}

	cout << sum << endl;


	return 0;
}