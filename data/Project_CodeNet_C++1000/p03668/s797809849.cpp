#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const LL N = 200005;

LL ec = 0,to[N << 1],nxt[N << 1],hed[N];
void add_edge(LL f,LL t){
	++ ec; to[ec] = t; nxt[ec] = hed[f]; hed[f] = ec;
}

LL sg[N];
void dfs(LL u,LL f){
	sg[u] = 0;
	for(LL i = hed[u];i;i = nxt[i]){
		LL v = to[i];
		if(v == f) continue;
		dfs(v,u);
		sg[u] ^= (sg[v] + 1);
	}
}

int main(){
	ios::sync_with_stdio(false);
	LL n,u,v;
	cin >> n;
	for(LL i = 1;i < n;i ++){
		cin >> u >> v;
		add_edge(u,v); add_edge(v,u);
	} dfs(1,0);
	cout << (sg[1] ? "Alice" : "Bob") << '\n';
	return 0;
}