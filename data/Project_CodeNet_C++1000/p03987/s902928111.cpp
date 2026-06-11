#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,a[200005],sta[200005],top,l[200005],r[200005];
long long ans=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
		r[i]=n+1;
	}
	for(int i=1;i<=n;++i){
		while(top && a[sta[top]]>=a[i]){
			r[sta[top]]=i;
			--top;
		}
		l[i]=sta[top];
		sta[++top]=i;
	}
	for(int i=1;i<=n;++i)
		ans+=(long long)(i-l[i])*(r[i]-i)*a[i];
	printf("%lld\n",ans);
	return 0;
}