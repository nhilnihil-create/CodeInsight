#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<locale.h>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long int ll;
const ll INF=pow(10,15);
ll N;
//29
int main()
{
scanf("%lld",&N);
int ans=1000;
for(int i=1;i<=min(N,(ll)100000);i++)
{
	if(N%i==0)
	{
		ll a=N/i,b=i;
		int diga=0,digb=0;
		for(;;){diga++; a/=10; if(a==0){break;}}
		for(;;){digb++; b/=10; if(b==0){break;}}
		diga=max(diga,digb);
		ans=min(ans,diga);
	}
}
printf("%d\n",ans);
} 