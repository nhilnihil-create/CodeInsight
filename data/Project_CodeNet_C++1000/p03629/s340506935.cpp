#include<cstdio>
#include<cstring>
const int N=2e5+7,inf=0x3f3f3f3f;
int dp[N],nxt[N][26],n,x,i,j;char s[N];
int main(){
	for(scanf("%s",s+1),n=strlen(s+1),i=0;i<26;++i)nxt[n][i]=n+1;
	for(memset(dp,inf,sizeof(dp)),dp[n+1]=0,i=n;i>=0;--i){
		for(j=0;j<26;++j)if(dp[i]>dp[x=nxt[i][j]]+1)dp[i]=dp[x]+1;
		if(i)memcpy(nxt[i-1],nxt[i],sizeof(nxt[i])),nxt[i-1][s[i]-'a']=i;
	}
	for(x=0;x<n+1;){
		for(j=0;j<26;++j)if(dp[nxt[x][j]]==dp[x]-1){
			putchar(j+'a');x=nxt[x][j];break;
		}
	}
	return 0*puts("");
}