#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100005
#define LL long long
int a[N],op[N];
LL sum[N];
char s[4];
int main()
{
	int n,i,j;
	scanf("%d%d",&n,&a[1]);op[1]=1;
	for(i=2;i<=n;i++){
		scanf("%s%d",s,&a[i]);
		if(s[0]=='-')op[i]=-1;
		else op[i]=1;
	}
	for(i=n;i>=1;i--)sum[i]=sum[i+1]+a[i];
	LL s1=0,s2,ans=-0x3f3f3f3f3f3f3f3fll;
	for(i=2;i<=n;i++){
		s1+=1ll*a[i-1]*op[i-1];
		if(op[i]==-1){
			s2=1ll*a[i];
			for(j=i+1;j<=n;j++){
				if(op[j]==-1)break;
				s2+=1ll*a[j];
			}
			ans=max(ans,s1-s2+sum[j]);
		}
	}
	s1+=1ll*a[n]*op[n];
	printf("%lld",max(s1,ans));
}