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
 
int n;
ll T,ans;
ll t[maxn],pre[maxn];
 
ll read(){ ll s=0,f=1; char ch=getchar(); while(ch<'0' || ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } while(ch>='0' && ch<='9'){ s=s*10+ch-'0'; ch=getchar(); } return s*f; }
 
int main(){
	memset(pre,0,sizeof(pre));
	ans = 0;
	n = read(),T = read();
	
	for(int i=1;i<=n;i++){
		t[i]=read();
		pre[i]=t[i];
	} 
	pre[n+1]=1e18+7;
	
//	for(int i=1;i<=n;i++){
//		printf("%d ",pre[i]);
//	}printf("\n");
	
	int nex = 1;
	
	for (int i = 1;i <= n ;i = nex){
		nex = lower_bound(pre+1,pre+1+n,pre[i]+T)-pre;
		ans+=pre[nex-1]-pre[i]+min(pre[nex]-pre[nex-1],T);
//		printf("%lld %d\n",ans,nex);
	}
	
//  ans += T;
	printf("%lld\n",ans);
	
	return 0;
}