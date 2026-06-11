// luogu-judger-enable-o2
#include<bits/stdc++.h>
#define maxn 100010
#define LL long long
using namespace std;
LL n,a[maxn],y,id[maxn],vis[maxn],stk[maxn],top,k,m,ans[maxn];
int main(){
	scanf("%lld",&n);
	for(LL i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		id[i]=i;
	}
	for(LL i=n;i>=1;i--){//做差分 
		a[i]-=a[i-1];
	}
	scanf("%lld%lld",&m,&k);
	for(LL i=1;i<=m;i++){
		scanf("%lld",&y);
		swap(id[y],id[y+1]);//（难点）归纳出来的规律 
	}
	for(LL i=1;i<=n;i++){
		if(vis[i]==0){
			top=0;
			for(LL j=i;!vis[j];j=id[j]){
				stk[++top]=j;
				vis[j]=1;
			}
			for(LL j=1;j<=top;j++){
				ans[stk[j]]=a[stk[(k+j-1)%top+1]];
			}
		}
	}
	for(LL i=1;i<=n;i++){
		ans[i]+=ans[i-1];//期望值的可加性 
		printf("%lld\n",ans[i]);
	}
	return 0;
}//a b c d e f