#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define lg long long
#define db double
#define lb(x) ((x)&-(x))
#define ft first
#define sd second

#define HII cerr<<"HI"<<endl
#define LLLINE cerr<<"@@@@@@@@@@@@@@@@@@@@"<<endl

template <class _T_>
void read(_T_& d){
	d=0;int f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f*=-1;
	for(;c>='0'&&c<='9';c=getchar())d=d*10+c-'0';
	d*=f;
}

/************************************************/
#define MN 200005
int n;
int a[MN];
int main(){
	read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	int cnt=0;
	while(1){
		int tot=0,F=0;
		for(int i=1;i<=n;++i){
			if(a[i]==1){
				F=1;break;
			}
			tot+=a[i]&1;
		}
		if(F){
			int tot=0;
			for(int i=1;i<=n;++i){
				tot+=a[i]-1;
			}
			tot&=1;
			cnt^=tot;
			break;
		}
		if(tot==1&&!((n-tot)&1)){
			int g=0;
			for(int i=1;i<=n;++i){
				a[i]/=2;
				g=__gcd(a[i],g);
			}
			for(int i=1;i<=n;++i)a[i]/=g;
		}else{
			cnt^=(n-tot)&1;break;
		}
		cnt^=1;
	}
	puts(cnt?"First":"Second");
	return 0;
}
