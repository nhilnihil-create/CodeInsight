#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXSIZE=10000020;
const ll INF=0x3f3f3f3f3f3f3f3fLL;
int bufpos;
char buf[MAXSIZE];
#define NEG 1
void init(){
	#ifdef LOCAL
		freopen("C.txt","r",stdin);
	#endif
	buf[fread(buf,1,MAXSIZE,stdin)]='\0';
	bufpos=0;
}
#if NEG
int readint(){
	bool isneg=0;
	int val=0;
	for(;!isdigit(buf[bufpos]);bufpos++)
		if (buf[bufpos]=='-')
			isneg=1;
	for(;isdigit(buf[bufpos]);bufpos++)
		val=val*10+buf[bufpos]-'0';
	return isneg?-val:val;
}
#else
int readint(){
	int val=0;
	for(;!isdigit(buf[bufpos]);bufpos++);
	for(;isdigit(buf[bufpos]);bufpos++)
		val=val*10+buf[bufpos]-'0';
	return val;
}
#endif
char readchar(){
	for(;isspace(buf[bufpos]);bufpos++);
	return buf[bufpos++];
}
int readstr(char* s){
	int cur=0;
	for(;isspace(buf[bufpos]);bufpos++);
	for(;!isspace(buf[bufpos]);bufpos++)
		s[cur++]=buf[bufpos];
	s[cur]='\0';
	return cur;
}
int a[100002];
ll dp[100002][4];
inline void tense(ll &x,ll y){
	if (x<y)
		x=y;
}
int main(){
	init();
	int n=readint();
	for(int i=1;i<=n;i++){
		a[i]=readint();
		// printf("%d\n",a[i]);
	}
	for(int i=0;i<=n+1;i++)	
		for(int j=0;j<4;j++)
			dp[i][j]=-INF;
	dp[1][0]=0;
	for(int i=1;i<=n;i++){
		int sgn=1;
		for(int j=0;j<3;j++){
			// printf("dp[%d][%d]=%lld\n",i,j,dp[i][j]);
			//0 0
			tense(dp[i+1][j],sgn*a[i]+dp[i][j]);
			//0 1
			if (j)
				tense(dp[i+1][j-1],sgn*a[i]+dp[i][j]);
			//1 0
			if (a[i]<0)
				tense(dp[i+1][j+1],sgn*a[i]+dp[i][j]);
			sgn=-sgn;
		}
	}
	printf("%lld",dp[n+1][0]);
}