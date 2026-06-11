#include <bits/stdc++.h>
const int N=200000+10;
char s[N];int n,tr[N][26];
int vis[N],dp[N],use[N];
int dfs(int x){
	if(vis[x]) return dp[x];
	if(x>n) return 0;
	int &r=dp[x],tmp=0; r=N+1;
	for(int i=0;i<26;i++){
		int j=tr[x][i]; tmp=1+dfs(j);
		if(r>tmp){ r=tmp; use[x]=i; }
	}
	vis[x]=1;return r;
}
int main(){
	std::cin>>(s+1); n=strlen(s+1);
	for(int i=0;i<=n;i++) std::fill(tr[i],tr[i]+26,n+1);
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<26;j++) tr[i][j]=tr[i+1][j];
		tr[i][s[i+1]-'a']=i+1;
	}
	dfs(0);
	fprintf(stderr,"len=%d\n",dp[0]);
	int q=0; while(q<=n){
		putchar(char(use[q]+'a'));
		q=tr[q][use[q]];
	}
	return 0;
}
