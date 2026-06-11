#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#define SF scanf
#define PF printf
#define MAXN 100010
using namespace std;
typedef long long ll;
ll k;
int n,m,t;
int gt[MAXN];
ll a[MAXN],pre[MAXN],ans[MAXN];
vector<int> num;
bool vis[MAXN];
void got(int x){
	vis[x]=1;
	if(num.size()>=1&&x==num[0])
		return ;
	num.push_back(x);
	got(gt[x]);
}
int main(){
	SF("%d",&n);	
	for(int i=1;i<=n;i++)
		SF("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		pre[i]=a[i]-a[i-1];
	SF("%d%lld",&m,&k);
	for(int i=1;i<=n;i++)
		gt[i]=i;
	for(int i=1;i<=m;i++){
		SF("%d",&t);	
		swap(gt[t],gt[t+1]);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]!=0)
			continue;
		got(i);
		int len=num.size();
		ll k1=k%len;
		for(int j=0;j<len;j++)
			ans[num[j]]=pre[num[(j+k1)%len]];
		num.clear();
	}
	ll sum=0;
	for(int i=1;i<=n;i++){
		sum+=ans[i];
		PF("%lld.0\n",sum);
	}
}
//