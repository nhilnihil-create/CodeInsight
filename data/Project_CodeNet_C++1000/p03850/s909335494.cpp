#include <bits/stdc++.h>
using namespace std;
#define lor(a,b,c) for(register int a=b;a<=c;++a)
#define ror(a,b,c) for(register int a=c;a>=b;--a)
typedef long long ll;

const int N=1e5+5;
int n,nxt[N]; ll a[N],sum[N],abssum[N],ans;

template <typename T> inline T read(){
	char tmp=getchar(); T sum=0; bool flag=false;
	while(tmp<'0'||tmp>'9'){
		if(tmp=='-') flag=true; tmp=getchar();
	}
	while(tmp>='0'&&tmp<='9'){
		sum=(sum<<1)+(sum<<3)+tmp-'0'; tmp=getchar();
	}
	return flag?-sum:sum;
}

int main(){
	n=read<int>(); lor(i,1,n) a[i]=read<ll>(),sum[i]=sum[i-1]+a[i],abssum[i]=abssum[i-1]+abs(a[i]); ans=sum[n];
	nxt[n+1]=n+1; sum[n+1]=sum[n]; abssum[n+1]=abssum[n]; ror(i,1,n) {if(a[i+1]<0) nxt[i]=i+1; else nxt[i]=nxt[i+1];}
	lor(i,1,n) if(a[i]<0){
		ans=max(ans,sum[i-1]+(abssum[n]-abssum[nxt[i]-1])-(abssum[nxt[i]-1]-abssum[i-1]));
	}
	printf("%lld\n",ans);

	return 0;
}