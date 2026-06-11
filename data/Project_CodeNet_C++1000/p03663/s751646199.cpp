#include<iostream>
#include<cstdio>
using namespace std;
char s[10];
bool read()
{
	scanf("%s",s);
	return s[0]=='Y';
}
int main()
{
	long long n=1;
	for(int i=0;i<=10;i++,n=n*10)
	{
		printf("? %lld\n",n);fflush(stdout);
		if(!read()) break;
	}
	if(n==100000000000LL)
	{
		n=1;
		for(int ck=2;ck<=2000000000;ck=ck*10,n=n*10)
		{
			printf("? %d\n",ck);fflush(stdout);
			if(read())
			{
				printf("! %lld\n",n);fflush(stdout);
				return 0;
			}
		}
	}
	//cout<<n<<endl;
	long long ma=n/10;
	for(n=0;ma>1;ma/=10,n=n*10)
	{
		int l=-1,r=8,mid;
		while(l<r)
		{
			mid=(l+r+1)/2;
			printf("? %lld\n",n+mid+1);fflush(stdout);
			if(!read()) r=mid-1;
			else l=mid;
		}
		n+=l+1;
	}
	n*=10;
	for(int i=8;i>=0;i--)
	{
		printf("? %lld\n",n+i*10);fflush(stdout);
		if(!read())
		{
			printf("! %lld\n",n/10+i+1);fflush(stdout);
			return 0;
		}
	}
	printf("! %lld\n",n/10);fflush(stdout);
	return 0;
}
		