#include <iostream>
#include <cstdio>
#include <vector>
#define N 1005
using namespace std;

typedef long long ll;
ll n, m, mx[N];
vector<ll> gr[N], ga[N];
int main()
{
	ll i, j, k, t1, t2, t3;
	cin >> n >> m;
	while (m--) {
		scanf("%lld %lld %lld", &t1, &t2, &t3);
		gr[t1].push_back(t2); ga[t1].push_back(t3);
	}
	for (i = 2; i <= n; i++) mx[i] = -1e18;
	for (i = 0; i < n; i++) {
		for (j = 1; j <= n; j++) {
			if (mx[j] == -1e18) continue;
			for (k = 0; k < gr[j].size(); k++) {
				if (mx[j] + ga[j][k] > mx[gr[j][k]]) {
					if (i == n - 1 && gr[j][k] == n) {puts("inf"); return 0;}
					mx[gr[j][k]] = mx[j] + ga[j][k];
				}
			}
		}
	}
    cout << mx[n];
    return 0;
}