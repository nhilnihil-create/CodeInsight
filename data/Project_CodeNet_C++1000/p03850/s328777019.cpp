#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::mt19937 rnd(time(NULL));
#define rand rnd
#define pr std::pair<int,int>
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
#ifdef mod
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
template<class Ta,class Tb>void inc(Ta&a,Tb b){a=a+b>=mod?a+b-mod:a+b;}
template<class Ta,class Tb>void dec(Ta&a,Tb b){a=a>=b?a-b:a+mod-b;}
#endif
int A[100010];char ch[100010];
ll f[100010][3];
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)A[i]=gi(),ch[i]=getchar();
	for(int i=1;i<=n;++i)if(ch[i]=='-')A[i+1]*=-1;
	++n;
	memset(f,-63,sizeof f);
	f[0][0]=0;
	for(int i=1;i<=n;++i)
		for(int j=0;j<3;++j){
			for(int k=0;k<3;++k){
				if(k>=j)cxk(f[i][j],f[i-1][k]+A[i]*(j&1?-1:1));
				if(A[i]<0&&j&&k>=j-1)cxk(f[i][j],f[i-1][k]+A[i]*(~j&1?-1:1));
			}
		}
	printf("%lld\n",f[n][0]);
	return 0;
}
