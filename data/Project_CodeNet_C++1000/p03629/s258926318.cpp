#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-6;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
char in[210000];
int nx[210000][26];
int tmp[26];
char out[210000];
int dp[210000];
int use[210000];
int n;
int dfs(int a){
	if(~dp[a])return dp[a];
	if(a==n+1)return 0;
	int ret=mod;
	int at=0;
	for(int i=0;i<26;i++){
		int tmp=dfs(nx[a][i])+1;
		if(tmp<ret){
			ret=tmp;at=i;
		}
	}
	use[a]=at;
	return dp[a]=ret;
}
int main(){
	scanf("%s",in);
	n=strlen(in);
	for(int i=0;i<26;i++)tmp[i]=nx[n][i]=n+1;
	for(int i=n-1;i>=0;i--){
		tmp[in[i]-'a']=i+1;
		for(int j=0;j<26;j++)nx[i][j]=tmp[j];
	}
	for(int i=0;i<210000;i++)dp[i]=-1;

	dfs(0);
	int sz=0;
	int now=0;
	while(now<n+1){
		out[sz++]=use[now]+'a';
		now=nx[now][use[now]];
	}
	printf("%s\n",out);
}