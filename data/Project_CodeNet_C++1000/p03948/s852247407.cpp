#include<bits/stdc++.h>
using namespace std;

int arr[100100];

main()
{
	int n,t;
	scanf("%d %d",&n,&t);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int spot=0;
	int st=arr[0],most=0;
	for(int i=1;i<n-1;i++)
	{
		if(arr[i]>=arr[i+1])
		{
			int ben=arr[i]-st;
			if(ben>0&&ben>most)
			{
				most=ben;
				spot=1;
			}
			else if(ben>0&&ben==most)spot++;
		}
		st=min(st,arr[i]);
	}
	int ben=arr[n-1]-st;
	if(ben>0&&ben>most)
	{
		most=ben;
		spot=1;
	}
	else if(ben>0&&ben==most)spot++;
	printf("%d",spot);
}