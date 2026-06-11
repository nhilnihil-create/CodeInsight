#include<cstdio>
#include<map>
#include<iostream>
using namespace std;
const int MAXN = 2*int(1E5);
int fa1[MAXN + 5], fa2[MAXN + 5];
int Find1(int x) {
	if( fa1[x] == x ) return x;
	else return fa1[x] = Find1(fa1[x]);
}
int Find2(int x) {
	if( fa2[x] == x ) return x;
	else return fa2[x] = Find2(fa2[x]);
}
map<pair<int, int>, int> Map;
int main() {
	int N, K, L;
	scanf("%d%d%d", &N, &K, &L);
	for(int i=1;i<=N;i++)
		fa1[i] = fa2[i] = i;
	for(int i=1;i<=K;i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		int fx = Find1(u), fy = Find1(v);
		fa1[fx] = fy;
	}
	for(int i=1;i<=L;i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		int fx = Find2(u), fy = Find2(v);
		fa2[fx] = fy;
	}
	for(int i=1;i<=N;i++)
		Map[make_pair(Find1(i),Find2(i))]++;
	for(int i=1;i<N;i++)
		printf("%d ", Map[make_pair(Find1(i),Find2(i))]);
	printf("%d\n", Map[make_pair(Find1(N),Find2(N))]);
}