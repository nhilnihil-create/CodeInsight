#include<cstdio>
#include<cstring> 
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i<=b;i--)
using namespace std;
int a[110000];
const int mo=1e9+7;
int main()
{
	int n;
	scanf("%d",&n);
	int ans=1,lst=1;
	for(int i=1,num=1;num<=n;i++,num++)
	{
		int x;
		scanf("%d",&x);
		a[num]=x;
		while (x<i*2-2) i--;
		//if (a[num-1]==1 && a[num]==2) ans=ans*2; else
		ans=(long long)ans*i%mo;
		if (x==i*2-2) i--;
	}	
	printf("%d\n",ans);
}