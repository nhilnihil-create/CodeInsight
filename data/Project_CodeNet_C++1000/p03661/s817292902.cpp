#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXSIZE=30000020;
const ll INF=0x3f3f3f3f3f3f3f3fLL;
int bufpos;
char buf[MAXSIZE];
#define NEG 1
void init(){
	#ifdef LOCAL
		freopen("E.txt","r",stdin);
	#endif
	buf[fread(buf,1,MAXSIZE,stdin)]='\0';
	bufpos=0;
}
#if NEG
int readint(){
	bool isneg;
	int val=0;
	for(;!isdigit(buf[bufpos]) && buf[bufpos]!='-';bufpos++);
	bufpos+=(isneg=buf[bufpos]=='-');
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
ll sum[200002];
ll myabs(ll x){
	return x>0?x:-x;
}
int main(){
	init();
	int n=readint();
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+readint();
	ll ans=INF;
	for(int i=1;i<n;i++)
		ans=min(ans,myabs(sum[n]-sum[i]-sum[i]));
	printf("%lld",ans);
}