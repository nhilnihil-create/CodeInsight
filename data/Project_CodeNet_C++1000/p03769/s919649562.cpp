#include <bits/stdc++.h>
#define mset(a,b) memset(a,b,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof b)
#define max(a,b) ((a)<(b)?(b):(a))
#define lb(x) ((x)&(-(x)))
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
ll n;
int cnt=0,ans[505],l,r=501;
int main(){
	cin>>n;
	while(n){
		if(n&1)ans[--r]=++cnt,n>>=1;
		else ans[++l]=++cnt,n--;
	}
	printf("%d\n",cnt<<1);
	for(int i=1;i<=l;i++)printf("%d ",cnt-ans[i]+1);
	for(int i=r;i<=500;i++)printf("%d ",cnt-ans[i]+1);
	for(int i=1;i<=cnt;i++)printf("%d ",i);
	return 0;
}