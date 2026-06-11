#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n,m;
vector<int> way[maxn];
int sz,bad;
int num[maxn];
void dfs(int u) {
    sz++;
    for(auto v : way[u]) {
        if(num[v]==num[u]) bad = 1;
        if(num[v]!=-1) continue;
        num[v] = !num[u]; dfs(v);
    }
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		int u,v; scanf("%d%d",&u,&v);
		way[u].push_back(v); way[v].push_back(u);
	}
	for(int i=1;i<=n;i++) num[i] = -1;
	long long indy = 0, cnt0 = 0, cnt1 = 0;
	for(int u=1;u<=n;u++) {
        if(num[u]!=-1) continue;
        bad = 0; sz = 0;
        num[u] = 0; dfs(u);
        if(sz==1) indy++;
        else if(!bad) cnt0++;
        else cnt1++;
	}
//	printf("%lld %lld %lld\n",indy,cnt0,cnt1);
	long long res = 2LL*indy*n - indy*indy + 2LL*cnt0*cnt0 + 2LL*cnt0*cnt1 + cnt1*cnt1;
	printf("%lld",res);
}
