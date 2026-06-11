#include <iostream>
using namespace std;
int p[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&p[i]);
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		if (p[i]==i)
		{
			ans++;
			i++;
		}
	}
	printf("%d",ans);
}