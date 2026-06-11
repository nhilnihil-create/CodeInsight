#include<iostream>
#include<cstdio>
#include<math.h>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<set>
#include<map>
#define INF 999999
#define EPS 1.0e-6

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<int, P> PP;

ll h, w;
int n;
ll num[11];
int dx[3] = { -1,0,1 };
int dy[3] = { -1,0,1 };

int main()
{
	cin >> h >> w;
	cin >> n;
	ll a, b;
	vector<P> grid;
	for (int i = 0; i<n; i++) {
		cin >> a >> b;
		for (int i = 0; i<3; i++) {
			ll k = a + dx[i];
			for (int j = 0; j<3; j++) {
				ll l = b + dy[j];
				if (2 <= k && 2 <= l&&k < h&&l < w) {
					grid.push_back(P(k, l));
				}
			}
		}
	}
	sort(grid.begin(), grid.end());
	/*
	for (int i = 0; i<grid.size(); i++) {
		cout << grid[i].first << " " << grid[i].second << endl;
	}
	*/

	int i = 1;
	int cur = 1;
	while (i<grid.size()) {
		if (grid[i] == grid[i - 1]) {
			cur++;
			i++;
		}
		else {
			num[cur]++;
			cur = 1;
			i++;
			//cout << "a " << i << endl;
		}
	}
	if(!grid.empty())num[cur]++;
	
	ll sum = 0;
	for (int i = 1; i<10; i++) {
		sum += num[i];
	}
	
	num[0] = (h-2)*(w-2) - sum;
	for (int i = 0; i<10; i++) {
		cout << num[i] << endl;
	}

	return 0;
}