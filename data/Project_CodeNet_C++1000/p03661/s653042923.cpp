#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
long long read(){
	long long x=0,w=1;
	char ch=0;
	while (ch<'0' || ch>'9'){
		if (ch=='-') w=-1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*w;
}
long long Abs(long long x){
	return x>0?x:(-x);
}
long long s[200010];
int main(){
	long long n;
	n=read();
	for (long long i=1;i<=n;++i)
		s[i]=s[i-1]+read();
	long long ans=1e18;
	for (long long i=1;i<n;++i)
		ans=ans<Abs(s[n]-s[i]-s[i])?ans:Abs(s[n]-s[i]-s[i]);
	printf("%lld\n",ans);
	return 0;
}