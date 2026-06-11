#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f3f3f;
struct node{
	int id,val;
	bool operator<(node b)const{
		if(val==b.val)return id>b.id;
		return val>b.val;
	}
}a[100100];
int ans[100100],n;
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i].val),a[i].id=i;
	sort(a+1,a+n+1);
	int minn=inf,now=1;
	while(now<=n){
		while(now<=n&&a[now].val==a[now+1].val)now++;
		if(now==n+1)break;
		minn=min(minn,a[now].id);
		ans[minn]+=now*(a[now].val-a[now+1].val);
		now++;
	}
	for(int i=1;i<=n;i++)
		printf("%lld\n",ans[i]);
}