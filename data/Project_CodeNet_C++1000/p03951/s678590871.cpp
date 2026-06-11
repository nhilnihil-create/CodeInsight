#include<cstdio>
using namespace std;
int n,ans;char a[105],b[105];
int main(){
	scanf("%d%s%s",&n,a+1,b+1);
	for (int i=1;i<=n;i++)
	for (int j=n-i+1,k=1;j<=n;j++,k++)
	if(a[j]^b[k]) break;else if(j==n) ans=i;
	printf("%d\n",2*n-ans);
	return 0;
}