#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;

const int maxn = 200010;

ll n,m,md,ans;
ll a[maxn],pre[maxn];;

ll read(){ ll s=0,f=1; char ch=getchar(); while(ch<'0' || ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } while(ch>='0' && ch<='9'){ s=s*10+ch-'0'; ch=getchar(); } return s*f; }

int main(){
	ans = 0 ;
	memset(pre,0,sizeof(pre));
	n=read();
	
	for(ll i=1;i<=n;i++)
	{
		a[i] = read();
		pre[i] = a[i];
		pre[i] += pre[i-1];
	}
//	for(ll i=1;i<=n;i++){
//		printf("%d ",pre[i]);
//	}printf("\n");
	
		ll ans1=0,ans2=0;
		md = 0;
		pre[0]=-1;
		for(ll i=0;i<n;i++){
			ll tmp = md;
	//		printf("%d\n",tmp);
			if(((pre[i]+tmp) * (pre[i+1]+tmp) >= 0)){
				if((pre[i]+tmp) < 0){
					md += (1ll - (pre[i+1]+tmp));
					ans1 += (1ll - (pre[i+1]+tmp));
				}else {
					md -= ((pre[i+1]+tmp) + 1ll);
					ans1 += (1ll + (pre[i+1]+tmp));
				}
			}
		}
		
		md = 0;
		pre[0]=1;
		for(ll i=0;i<n;i++){
			ll tmp = md;
	//		printf("%d\n",tmp);
			if(((pre[i]+tmp) * (pre[i+1]+tmp) >= 0)){
				if((pre[i]+tmp) < 0){
					md += (1ll - (pre[i+1]+tmp));
					ans2 += (1ll - (pre[i+1]+tmp));
				}else {
					md -= ((pre[i+1]+tmp) + 1ll);
					ans2 += (1ll + (pre[i+1]+tmp));
				}
			}
		}
		ans = min(ans1, ans2);
	
	printf("%lld\n",ans);
	
	return 0;
}
