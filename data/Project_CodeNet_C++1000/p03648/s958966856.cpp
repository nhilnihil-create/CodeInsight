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

ll K;

void solve(){
	cin >> K;
	int N = 50;
	ll A[55] = {};
	for(int i=1;i<=N;i++) A[i] = K / N + N - 1;
	K %= N;
	for(int i=1;i<=K;i++) {
		A[i] += N;
		for(int j=1;j<=N;j++) if(i != j) A[j]--;
	}
	printf("%d\n", N);
	for(int i=1;i<=N;i++) printf("%lld ", A[i]);puts("");
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}