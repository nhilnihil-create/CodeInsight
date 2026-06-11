#include<bits/stdc++.h>
#define MaxN 100000+100
int a[MaxN];
void swap(int q,int b)
{
	int c=a[q];
	a[q]=a[b];
	a[b]=c;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int sum=0;
	for(int i=1,next=i;i<=n;i=next+1,next=i)
	{
		if(a[i]==i)
		{
		//	printf("%d\n",i);
			while(next+1<=n && a[next+1]==next+1)
				next++;
			sum+=(next-i+1)/2+((next-i+1)%2);
		}	
	}
	printf("%d\n",sum);
	return 0;
}