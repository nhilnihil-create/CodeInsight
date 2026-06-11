#include<bits/stdc++.h>
using namespace std;
int n,t,a[100010];
int leftmin[100010],rightmax[100010];

int main()
{
	int i,j;
	
	scanf("%d %d",&n,&t);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	leftmin[0] = a[0];
	for(i=1;i<n;i++)
	{
		if(a[i] < leftmin[i-1])
		{
			leftmin[i] = a[i];
		}
		else leftmin[i] = leftmin[i-1];
	}
	
	rightmax[n-1] = a[n-1];
	for(i=n-2;i>=0;i--)
	{
		if(a[i] > rightmax[i+1])
		{
			rightmax[i] = a[i];
		}
		else rightmax[i] = rightmax[i+1];
	}
	
	int maxdif=0,cou=0,right,left;
	for(i=0;i<n;i++)
	{
//		printf("leftmin[%d] = %d		rightmax[%d] = %d\n",i,leftmin[i],i,rightmax[i]);
		if(maxdif < rightmax[i]-leftmin[i])
		{
			maxdif = rightmax[i]-leftmin[i];
			cou=1;
			right = rightmax[i];
			left = leftmin[i];
		}
		else if(maxdif == rightmax[i]-leftmin[i] && right!=rightmax[i] && left!=leftmin[i])
		{
			right = rightmax[i];
			left = leftmin[i];
			cou++;
		}
	}
	printf("%d\n",cou);
}