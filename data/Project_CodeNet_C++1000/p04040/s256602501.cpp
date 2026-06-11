#include<bits/stdc++.h>
#define maxn 200005
#define LL long long
using namespace std;

const LL mo=1e9+7;
LL n,m,a,b;
LL jc[maxn];
LL inv[maxn];
LL f[maxn];
LL sum;
LL ans;

LL ksm(LL a,LL k){
	if(!k)return 1ll;
	return (k&1)?a*ksm(a*a%mo,k>>1)%mo:ksm(a*a%mo,k>>1);
}

LL C(int x,int y){
	return (jc[y]*inv[x]%mo)*inv[y-x]%mo;
}

LL calc(int x,int y,int xx,int yy){
	return C(xx-x,xx+yy-x-y);
}

int main(){
	cin>>n>>m>>a>>b;
	jc[0]=1;
	for(LL i=1;i<maxn;i++)jc[i]=jc[i-1]*i%mo;
	inv[200000]=ksm(jc[200000],mo-2);
	for(LL i=199999;i>=0;i--)inv[i]=inv[i+1]*(i+1ll)%mo;
	ans=calc(1,1,n,m);
	for(int i=1;i<=b;i++){
		f[i]=calc(1,1,n-a+1,i);	
	}
	for(int i=1;i<=b;i++){
		f[i]-=sum;
		f[i]=(f[i]+mo)%mo;
		sum+=f[i];
		if(sum>=mo)sum-=mo;
		ans-=(f[i]*calc(n-a+1,i,n,m))%mo;
		ans=(ans+mo)%mo;
	}
	cout<<ans<<endl;
	return 0;
}