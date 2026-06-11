//by xxj
#include<bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
#define mp make_pair
#define ll long long
#define pii pair<int,int>
#define lowbit(x) x&-x
const int inf=1e9+7;
const double eps=1e-10;
const ll linf=1e18+7;
const ll hh=523;
//const int mod=;
ll cf[200007];
ll cfcf[200007];
int a[100007];
ll ans[200007];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	ll sum=0;
	for (int i=1;i<n;i++){
		int x=a[i-1],y=a[i];
		if (y<x){
			y+=m;
		}
		sum+=y-x;
		cfcf[x+2]+=1;
		cfcf[y+1]-=(y-x);
		cfcf[y+2]+=(y-x-1);
	}
	cf[0]=0;
	int cnt=0;
	for (int k=1;k<=2*m;k++){
		cf[k]=cf[k-1]+cfcf[k];
	}
	ans[0]=0;
	cnt=0;
	for (int i=1;i<=2*m;i++){
		ans[i]=ans[i-1]+cf[i];
	}
	ll mn=linf;
	for (int i=1;i<=m;i++){
		ans[i]+=ans[i+m];
		mn=min(sum-ans[i],mn);
	}
	printf("%lld\n",mn);
	return 0;
}
/*
input:
4 6
1 5 1 4
*/
