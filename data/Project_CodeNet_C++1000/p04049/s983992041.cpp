#include<bits/stdc++.h>
#define C getchar()
#define LL long long
#define mod 1000000007
using namespace std;
inline int read() {
	int num = 0;
	char c=C;
	for(;c<'0' || c>'9';c=C);
	for(;c>='0'&&c<='9';c=C) num = (num << 1) + (num << 3) + (c ^ 48);
	return num;
}

int n , k;
int nxt[10000],head[10000],to[10000],fr[10000],tot;

inline void add(int u,int v) {
	nxt[++tot] = head[u] , head[u] = tot , to[tot] = v , fr[tot] = u;
}

int ans = 0;
int dep[10000];
inline void dfs(int x,int fa){
    for(int i=head[x];i;i=nxt[i]){
        if(to[i] == fa) continue;
        dep[to[i]] = dep[x] + 1;
        dfs(to[i] , x);
    }
}


int main() {
	
	n = read() , k = read();
	for(int i=1;i<n;++i) {
		int u = read() , v = read();
		add(u , v);
		add(v , u);
	}
	
	int sum = 1 << 30;
	if (k & 1) {
		for(int i=1;i<=tot;i+=2) {
			for(int j=1;j<=n;++j) dep[j] = 0;
			ans = 0;
		    dfs(to[i] , fr[i]);dfs(fr[i] , to[i]);
		    for(int j=1;j<=n;++j) if (dep[j] > k >> 1) ++ ans;
		    sum = min(sum , ans);
		}
	}
	 else {
		for(int i=1;i<=n;++i) {
			for(int j=1;j<=n;++j) dep[j] = 0;
			ans = 0;
		    dfs(i , 0);
		    for(int j=1;j<=n;++j) if (dep[j] > k >> 1) ++ ans;
		    sum = min(sum , ans);
		}
	 }
	printf("%d",sum);
	return 0;
}
