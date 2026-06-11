#include <iostream>
#include <cstdio>
#define N 305
using namespace std;

typedef long long ll;
ll n, c, a[N][N];
bool v[N][N];
int main()
{
	ll i, j, k;
	cin >> n;
	for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) scanf("%lld", &a[i][j]);
	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (i == k || j == k) continue;
				if (a[i][j] > a[i][k] + a[k][j]) {puts("-1"); return 0;}
				if (a[i][j] == a[i][k] + a[k][j]) v[i][j] = 1;
			}
		}
	}
//	for (i = 1; i <= n; i++, puts("")) for (j = 1; j <= n; j++) printf("%d ", v[i][j]);
	for (i = 1; i <= n; i++) for (j = i + 1; j <= n; j++) c += (!v[i][j]) * a[i][j];
    cout << c << endl;
    return 0;
}