#include <iostream>
#include <fstream>
#include <utility>
#include <queue>
#include <vector>
#include <array>
#include <stack>
#include <list>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(ll (i)=(n-1);(i)>=0;(i)--)
#define bs(n) (1ull<<(n))

int main() {
	int n, m;
	cin >> n >> m;
	int* a = new int[m], * b = new int[m], * c = new int[m];
	rep(i, m) cin >> a[i] >> b[i] >> c[i];
	int d[101][101];
	rep(i, 101)rep(j, 101)d[i][j] = 1000000000;
	rep(i, m) d[a[i]][b[i]] = d[b[i]][a[i]] = c[i];
	rep(i, 101)rep(j, 101)rep(k, 101)d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
	int r = 0;
	rep(i, m)if (d[a[i]][b[i]] < c[i])r++;
	cout << r << endl;
}
