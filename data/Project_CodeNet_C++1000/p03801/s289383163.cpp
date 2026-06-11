#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define ll long long
int n,a[N],b[N],id[N];
ll ans[N];
inline bool cmp(int x,int y){
	return a[x]>a[y] || (a[x]==a[y] && x<y);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),b[i]=a[i],id[i]=i;
	sort(b+1,b+n+1);sort(id+1,id+n+1,cmp);
	
	for(int i=1,lst=0;i<=n;++i){
		if(i==1) lst=id[i];
		if(i==1 || a[id[i]]!=a[id[i-1]]){
			int p=lower_bound(b+1,b+n+1,a[id[i]])-b-1;
			lst=min(lst,id[i]);
			ans[lst]+=1ll*(a[id[i]]-b[p])*(n-p);
		}
	}
	for(int i=1;i<=n;++i) printf("%lld\n",ans[i]);
	return 0;
} 