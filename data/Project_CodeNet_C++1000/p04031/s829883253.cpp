//C - Be Together

#include <stdio.h>
int N;
int a[101];

int computeCost(int target)
{
	int cost = 0;
	for(int i=1;i<=N;i++)
	{
		cost += (a[i]-target)*(a[i]-target);
	}
	return cost;
}	

int main()
{
	int min = -101,max = 101,mincost;
	scanf("%d",&N);

	for (int i=1;i<=N;i++)
	{
		scanf("%d",&a[i]);

		if (a[i]<min)
			min = a[i];
		if (a[i]>max)
			max = a[i];
	}

	mincost = computeCost(min);

	for (int j=min;j<=max;j++)
	{
		int cost = computeCost(j);
		if (cost<mincost)
			mincost = cost;
	}

	printf("%d",mincost);

}