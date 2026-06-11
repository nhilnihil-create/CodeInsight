#include<stdio.h>
#include<queue>
#include<assert.h>
#include<tuple>
#include<string>
#include<algorithm>
#include<iostream>
#include<map>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef tuple<int,int,int> t3;

const int MX = 100005;
const int MM = 1000000007;

vector<int> G[MX];
int A[MX];

ll dfs(int x, int p){
	ll tot = 0, mx = 0;
	if( G[x].size() == 1 ) return A[x];
	for(int c : G[x]){
		if( c == p ) continue;
		ll t = dfs(c, x);
		mx = max(mx, t);
		tot += t;
	}
	if( A[x]*2 < tot || A[x] > tot){
		printf("NO\n");
		exit(0);
	}
	if( tot-A[x] < mx - (A[x]*2-tot) ){
		printf("NO\n");
		exit(0);
	}
	return A[x]*2 - tot;
}

int main()
{
	int N, v = 0;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", A+i);
	for(int i = 2; i <= N; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i = 1; i <= N; i++) if( G[i].size() >= 2 ) v = i;
	if( N == 2 ){
		printf("%s\n", A[1] == A[2] ? "YES":"NO");
	}
	else printf("%s\n", dfs(v, -1) ? "NO" : "YES");
}
