#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 19;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

const int MX = 4005;
const int MM = 998244353;

int D[MX][MX];

int main()
{
	map<int, int> L;
	int N;
	ll ans = 0;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++) scanf("%d", D[i]+j);
	}
	for(int i = 1; i <= N; i++){
		for(int j = i+1; j <= N; j++){
			int v = 1, ch = 0;
			for(int k = 1; k <= N; k++){
				if( k != i && k != j && D[i][k] + D[k][j] == D[i][j] ) v = 0;
				if( D[i][k] + D[k][j] < D[i][j] ) ch = 1;
			}
			if( ch ) return !printf("-1\n");
			if( v ) ans += D[i][j];
		}
	}
	printf("%lld\n", ans);
}
