#include<cstdio>
#include<cstring>
#include<algorithm>
#define SF scanf
#define PF printf
#define MAXN 100010
#define INF 0x3FFFFFFF
using namespace std;
typedef long long ll;
int n;
int a[MAXN];
bool flag[MAXN];
char s[20];
ll pre[MAXN];
ll sum,ans=-INF;
int main(){
	SF("%d",&n);
	flag[1]=0;
	SF("%d",&a[1]);
	for(int i=2;i<=n;i++){
		SF("%s",s);
		if(s[0]=='-')
			flag[i]=1;
		SF("%d",&a[i]);
	}
	for(int i=n;i>=1;i--)
		pre[i]=pre[i+1]+a[i];
	int las=1;
	while(flag[las]==0&&las<=n){
		sum+=a[las];
		las++;
	}
	while(las<=n){
		int las1=las+1;
		ll sum1=0;
		while(flag[las1]==0&&las1<=n){
			sum1+=a[las1];
			las1++;
		}
		if(las1<=n){
			ans=max(ans,sum-sum1-a[las]+pre[las1]);
		}
		sum-=a[las];
		las=las1;
		sum+=sum1;
	}
	ans=max(ans,sum);
	PF("%lld",ans);
}	