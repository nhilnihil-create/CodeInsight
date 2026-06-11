#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;

const int N=200005;

int n;
int dp[N],nxt[N][27],f[N],c[N];
char s[N];

void init(){
	int i,j;
	for (j=0;j<26;j++) nxt[n+1][j]=n+1;
	for (i=n;i>=1;i--){
		for (j=0;j<26;j++) nxt[i][j]=nxt[i+1][j];
		nxt[i][s[i]-'a']=i;
	} 
}

int main(){
	int i,j;
	scanf("%s",s+1); n=strlen(s+1);
	init();
	dp[n+1]=1;
	for (i=n;i>=1;i--){
		dp[i]=-1;
		for (j=0;j<26;j++)
			if (dp[i]==-1||dp[nxt[i][j]+1]+1<dp[i]){
				dp[i]=dp[nxt[i][j]+1]+1;
				f[i]=nxt[i][j]+1; c[i]=j;
			}
	}
	i=1;
	while (i<n){
		printf("%c",c[i]+'a');
		i=f[i];
	}
	return 0;
}