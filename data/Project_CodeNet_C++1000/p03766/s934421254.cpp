#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 2000006
#define mo 1000000007
using namespace std;
int n,sum,f[N];
int main()
{
	scanf("%d",&n);f[0]=1;f[1]=sum=n;
	for(int i=2;i<=n;i++){
		f[i]=(sum-f[i-2]+1LL*(n-1)*(n-1)%mo+(n-i+2)+mo)%mo;
		sum=(sum+f[i])%mo;
	}
	printf("%d\n",f[n]);
}