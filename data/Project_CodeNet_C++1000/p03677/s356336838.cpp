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

int IT_MAX = 1 << 18;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

const int MX = 300005;
const int MM = 1000000007;

int N, M;
pii D[MX], E[MX];

int dist(int x, int y){
	if(x <= y) return y-x;
	else return M+y-x;
}

int main()
{
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%d", &D[i].first);
	for(int i = 1; i <= N; i++) D[i].second = D[i+1].first;
	N--;
	
	vector<pii> Ev;
	int sz = 0;
	for(int i = 1; i <= N; i++){
		if( D[i].first < D[i].second ){
			E[++sz] = D[i];
			E[++sz] = pii(D[i].first + M, D[i].second + M);
		}
		else{
			E[++sz] = pii(D[i].first - M, D[i].second);
			E[++sz] = pii(D[i].first, D[i].second + M);
		}
	}
	for(int i = 1; i <= sz; i++){
		Ev.emplace_back(E[i].first, +i);
		Ev.emplace_back(E[i].second, -i);
	}
	sort(Ev.begin(), Ev.end());

	ll total = 0, cnt = 0, sum = 0, ans = 0;
	for(int i = 1; i <= N; i++) total += dist(D[i].first, D[i].second);
	ans = total;
	for(int i = 0, j = 0; i < Ev.size(); i = j){
//		printf("%d : %lld %lld %lld\n", Ev[i].first, total, sum, cnt);
		ans = min(ans, total + sum - cnt * Ev[i].first + cnt);
		for(; j < Ev.size() && Ev[j].first == Ev[i].first; j++){
			int ad = abs(Ev[j].second);
			if(Ev[j].second < 0){
				cnt--;
				sum -= E[ad].second;
				total += dist(E[ad].first, E[ad].second);
			}
			else{
				cnt++;
				sum += E[ad].second;
				total -= dist(E[ad].first, E[ad].second);
			}
		}
	}
	printf("%lld\n", ans);
}
