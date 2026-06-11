#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXSIZE=10000020;
int bufpos;
char buf[MAXSIZE];
#define NEG 0
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
struct bit{
	int n;
	ll a[100002];
	void add(int p,int v){
		for(;p;p-=p&-p)
			a[p]+=v;
	}
	ll query(int p){
		ll ans=0;
		for(;p<=n;p+=p&-p)
			ans+=a[p];
		return ans;
	}
}b,c;
pair<int,int> w[100002];
int a[100002],pre[100002];
ll sum[100002],cnt[100002];
int main(){
	init();
	int n=readint();
	for(int i=1;i<=n;i++){
		a[i]=readint();
		if (a[i]>=a[pre[i-1]])
			pre[i]=i;
		else pre[i]=pre[i-1];
		w[i]=make_pair(a[i],i);
	}
	sort(w+1,w+n+1);
	b.n=c.n=n;
	for(int i=n;i;i--){
		sum[w[i].second]=c.query(w[i].second+1);
		cnt[w[i].second]=b.query(w[i].second+1);
		b.add(w[i].second,1);
		c.add(w[i].second,w[i].first);
	}
	sum[0]=c.query(1);
	cnt[0]=n;
	for(int i=1;i<=n;i++){
		// printf("%d %lld %lld\n",pre[i],sum[i],cnt[i]);
		if (pre[i]==pre[i-1]){
			puts("0");
			continue;
		}
		ll ans=cnt[i]*(a[i]-a[pre[i-1]]);
		ans+=(sum[pre[i-1]]-sum[i])-(cnt[pre[i-1]]-cnt[i])*a[pre[i-1]];
		printf("%lld\n",ans);
	}
}
