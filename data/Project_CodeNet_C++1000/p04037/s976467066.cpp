#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int maxn=1e5+10;
int n;
int a[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,a+n);
//	for(int i=0;i<n;i++)
//		printf("%d ",a[i]);
//	printf("\n");
//	system("pause");
	int reachx,reachy;
	for(int i=0;i<n;i++)
	{
		if(a[i]>=(n-i))
		{
			reachx=i;
			reachy=n-i;
			break;
		}
	}
//	printf("%d %d\n",reachx,reachy);
//	printf("%d\n",a[reachx]);
//	system("pause");
	bool noleft=(!reachx)||(a[reachx-1]<reachy);
	bool noup=a[reachx]==reachy;
//	cout<<noleft<<" "<<noup<<endl;
	if(noleft&&noup)
	{
		printf("Second\n");
	}
	else if(noleft)
	{
		int up=a[reachx]-reachy;
		if(up&1)printf("First\n");
		else printf("Second\n");
	}
	else if(noup)
	{
		int lft=reachx-1;
		int clft=0;
		while(lft>=0&&a[lft]==a[reachx])
		{
			lft--;
			clft^=1;
		}
	//	cout<<clft<<endl;
		if(clft)printf("First\n");
		else printf("Second\n");
	}
	else
	{
		int up=a[reachx]-reachy;
	//	cout<<up<<endl;
		up&=1;
		int lft=reachx-1;
		int clft=0;
		while(lft>=0&&a[lft]==reachy)
		{
			lft--;
			clft^=1;
		}
	//	cout<<lft<<" "<<reachx<<" "<<a[lft]<<endl;
	//	cout<<up<<" "<<clft<<endl;
		if(up||clft)printf("First\n");
		else printf("Second\n");
	}
	return 0;
}