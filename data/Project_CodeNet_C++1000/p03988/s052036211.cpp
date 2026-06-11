#include <iostream>
using namespace std;
int cnt[105];
int main()
{
	int n,mx=0;
	scanf("%d",&n);
	while (n--)
	{
		int a;
		scanf("%d",&a);
		mx=max(mx,a);
		cnt[a]++;
	}
	int h=(mx+1)/2;
	for (int i=1;i<h;i++)
	{
		if (cnt[i])
		{
			printf("Impossible");
			return 0;
		}
	}
	for (int i=h;i<mx;i++)
	{
		if (!cnt[i])
		{
			printf("Impossible");
			return 0;
		}
	}
	if ((mx%2 && cnt[h]>2) || (mx%2==0 && cnt[h]>1))
	printf("Impossible");
	else
	printf("Possible");
}