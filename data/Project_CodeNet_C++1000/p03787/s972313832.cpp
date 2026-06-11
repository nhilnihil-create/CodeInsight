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

int D[MX], O[MX];
int N, K, M;

vector<int> G[MX];
int vst[MX], C[MX];

bool dfs(int x){
	if( vst[x] ) return true;
	vst[x] = 1;
	bool ch = 1;
	for(int c : G[x]){
		if( vst[c] && C[c] + C[x] != 1 ) ch = 0;
		if( !vst[c] ) C[c] = !C[x];
		ch &= dfs(c);
	}
	return ch;
}

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	ll p = 0, q = 0, r = 0;
	for(int i = 1; i <= N; i++){
		if( vst[i] ) continue;
		if( G[i].size() == 0 ) p++;
		else if( dfs(i) ) q ++;
		else r ++;
	}
	printf("%lld\n", 2*p*N - p*p + r*r + q*q*2 + q*r*2);
}
