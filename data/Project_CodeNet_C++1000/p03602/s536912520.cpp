#include <cstdio>
#include <memory.h>
#include <cstring>
#include <vector>
#include <deque>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <functional>
#include <set>
#include <list>
#include <map>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long llu;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
const ll MOD = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;

struct node {
	int u, v, c;
	bool operator< (const node &v2) const {
		return c > v2.c;
	}
};

priority_queue<node> pq;

int mat[300][300];
int temp[300][300];
bool al[300][300];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &mat[i][j]);
	memcpy(temp, mat, sizeof(temp));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++) {
				if (i == j || i == k || j == k) continue;
				if (mat[j][k] == mat[j][i] + mat[i][k]) al[k][j] = al[j][k] = 1;
				mat[j][k] = min(mat[j][k], mat[j][i] + mat[i][k]);
			}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (mat[i][j] != temp[i][j]) return !printf("-1");

	memcpy(mat, temp, sizeof(mat));

	ll ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (al[i][j] == 0) ans += mat[i][j];

	printf("%lld", ans / 2);
}

// 그리디하게 큰 것부터 지워보자.