
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<functional>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<numeric>
#include<limits>
#include<iterator>

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define rep(i,n) for(int i=0; i<n; i++)

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ll, char> plc;

int x[310][310];
int tmp[310][310];
int n;

ll sumcost;
int mincost[310];
bool used[310];

void warshallFloid() {
	rep(k, n) rep(i, n) rep(j, n)
		tmp[i][j] = min(tmp[i][j], tmp[i][k] + tmp[k][j]);
}

int main()
{
	cin >> n;
	rep(i, n) {
		rep(j, n) {
			cin >> x[i][j];
			sumcost += x[i][j];
			tmp[i][j] = x[i][j];
		}
	}

	sumcost /= 2;

	warshallFloid();

	bool f = true;
	rep(i, n) {
		rep(j, n) {
			if (x[i][j] != tmp[i][j])
				f = false;
		}
	}

	if (f) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (k == i || k == j)continue;

					if (tmp[i][j] == (tmp[i][k] + tmp[k][j])) {
						sumcost -= tmp[i][j];
						break;
					}
				}
			}
		}
		cout << sumcost << endl;
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}