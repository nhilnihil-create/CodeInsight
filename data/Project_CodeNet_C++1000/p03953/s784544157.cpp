#include <iostream>
#include <cstdio>
#include <cmath>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=2e5+5;
long long a[N],n,m,k,vis[N],b[N],cnt,lop[N],ans[N],res[N];
int main(){
	scanf("%lld",&n);
	rep(i,1,n) scanf("%lld",&a[i]);
	per(i,n,1) a[i]=a[i]-a[i-1],b[i]=i;
	scanf("%lld%lld",&m,&k);
	rep(i,1,m){
		int R;
		scanf("%d",&R);
		swap(b[R],b[R+1]);
	}
	rep(i,1,n){
		if(vis[i]) continue;
		lop[cnt=1]=i;
		for(int pos=b[i];pos!=i;pos=b[pos]){
			vis[pos]=1;
			lop[++cnt]=pos;
		}
		rep(j,1,cnt) ans[lop[j]]=lop[(j+k-1)%cnt+1];
	}
	rep(i,1,n) res[i]=a[ans[i]];
	rep(i,1,n) printf("%lld.0\n",res[i]+=res[i-1]);
	return 0;
}
