#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int n,arr[100005],totalgenap,totalganjil,yangganjil;
bool ans=true;
int FPB(int a,int b)
{
	if(b==0)
		return a;
	else
		return FPB(b,a%b);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	while(true)
	{
		totalgenap=0;
		totalganjil=0;
		for(int i=1;i<=n;i++)
		{
			if(arr[i]%2==0)
				totalgenap++;
			else
				totalganjil++,yangganjil=i;
		}
		if(totalgenap%2==1)
		{
			//ans=ans&&true;		//tergantung turnya siapa
			break;
		}
		else		//if(totalgenap%2==0)
		{
			if(totalganjil>=2||(totalganjil==1&&arr[yangganjil]==1))
			{
				ans=ans^true;
				break;
			}
			arr[yangganjil]--;
			int fpb;
			fpb=arr[1];
			for(int i=2;i<=n;i++)
				fpb=FPB(fpb,arr[i]);
			for(int i=1;i<=n;i++)
				arr[i]/=fpb;
			ans=ans^true;
		}
	}
	if(ans)
		printf("First\n");
	else
		printf("Second\n");
}