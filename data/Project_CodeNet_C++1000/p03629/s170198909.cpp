#include <bits/stdc++.h>
using namespace std;
#define maxn 200050
char input[maxn];
int nxt[maxn][26],dp[maxn];
int main(){
	scanf("%s",input+1);
	int n=strlen(input+1);
	for(int i=0;i<26;++i)
		nxt[n][i]=n+1;
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<26;++j){
			nxt[i][j]=nxt[i+1][j];
		}
		nxt[i][input[i+1]-'a']=i+1;
	}
	for(int i=n;i>=0;i--){
		dp[i]=1e9;
		for(int j=0;j<26;++j)
			dp[i]=min(dp[i],dp[nxt[i][j]]+1);
	}
	int index=0;
	while(index!=n+1){
		for(int j=0;j<26;++j){
			if(dp[index]==dp[nxt[index][j]]+1){
				index=nxt[index][j];
				printf("%c",'a'+j);
				break;
			}
		}
	}
	return 0;
}
