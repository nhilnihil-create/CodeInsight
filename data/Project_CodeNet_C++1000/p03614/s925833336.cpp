#include<bits/stdc++.h>
#define LL long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=100005;
int n,a[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int ans=0;
	for(int l=1;l<=n;l++){
		int r=l;
		for(;r<=n;r++) if(a[r]!=r) break;
		if(l!=r) ans+=(int)ceil((r-l)/2.0);
		l=r;
	}
	printf("%d\n",ans);
	return 0;
}