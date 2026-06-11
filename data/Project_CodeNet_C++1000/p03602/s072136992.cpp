#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

int N, A[310][310], B[310][310];

void solve(){
	scanf("%d", &N);
	for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) scanf("%d", A[i]+j), B[i][j] = A[i][j];
	int ok[310][310] = {};
	for(int k=1;k<=N;k++) for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
		if(B[i][j] > B[i][k] + B[k][j]) {
			puts("-1");
			return;
		}
		else if(i != k && k != j && B[i][j] == B[i][k] + B[k][j]) ok[i][j] = 1;
	}
	ll ans = 0;
	for(int i=1;i<=N;i++) for(int j=i;j<=N;j++) ans += !ok[i][j] * A[i][j];
	printf("%lld\n", ans);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}