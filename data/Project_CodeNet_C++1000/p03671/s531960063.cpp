#include<bits/stdc++.h>
using namespace std;
int main()

{
	int arr[3],i;
	for(i=0;i<3;i++)
	{
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+3);
	printf("%d\n",arr[0]+arr[1]);
}