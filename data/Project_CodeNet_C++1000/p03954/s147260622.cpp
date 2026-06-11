#include<bits/stdc++.h>
#define rg register int
#define il inline
#define mid ((l+r)>>1)
#define  big(i,j)  (a[n+i]>x&&a[n+i+j]>x)
#define sma(i,j) (a[n+i]<=x&&a[n+i+j]<=x)
#define el else if
using namespace std;
il long long read(){
    register long long x=0,f=1;
    register char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch<='9'&&ch>='0'){
        x=10*x+ch-'0';
        ch=getchar();
    }
    return x*f;
}
const int N=1000007;
typedef long long ll;
ll n,m,w,a[N];
bool chk(int x){
	for(rg i=0;i<n;++i){
		if(big(i,1)||big(-i,-1))return false;
		el(sma(i,1)||sma(-i,-1)) return true;
	}
	return a[1]<=x;
}
int main()
{
	n=read();
	for(rg i=1;i<(n<<1);++i){
		a[i]=read();
	}
	ll l=1,r=n<<1;--r;
	while(l<r){//r为答案 
		if(chk(mid)) r=mid;
		else l=mid+1;
	}
	printf("%lld\n",r);
	return 0;
}