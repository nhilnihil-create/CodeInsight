#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int maxs=-1;
	int mins;
	int num=0;
	for(int i=1;i<=n;i++)
	{
		int temp;
		scanf("%d",&temp);
		if(i==1)
		{
			mins=temp;
		}
		if(temp<mins)
		{
			mins=temp;
		}
		if(temp-mins>maxs)
		{
			maxs=temp-mins;
			num=1;
		}
		else if(temp-mins==maxs)
		{
			num++;
		}
	//	printf("%d\n",num);
	}
	printf("%d\n",num);
	return 0;
}