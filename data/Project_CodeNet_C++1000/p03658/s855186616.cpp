#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,k,l[50],i,x=0;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&l[i]);
	}
	sort(l,l+n);
	for(i=n-1;i>=n-k;i--){
		x+=l[i];
	}
	printf("%d\n",x);
	return 0;
}
