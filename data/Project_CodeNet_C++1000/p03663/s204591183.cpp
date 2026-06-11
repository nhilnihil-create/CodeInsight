#include<iostream>
#include<cstdio>
using namespace std;
long long t,l,r,mid;
char c;
void doit1(long long n)
{
	long long ts=n;
	while(ts)
	{
		ts=(ts-9)/10;
		if (ts==0) break;
		cout<<"? "<<ts<<endl;
		cin>>c;
		if (c=='N')
		{
			cout<<"! "<<ts+1<<endl;
			exit(0);
		}
	}
	ts=n+1;
	while(1)
	{
		if (ts>=1e12)
		{
			cout<<"! "<<1<<endl;
			exit(0);
		}
		cout<<"? "<<ts<<endl;
		cin>>c;
		if (c=='N') 
		{
			l=ts/10*9;
			r=ts-1;
			return;
		}
		ts*=10;
	}
}
int main()
{
	fflush(stdout);
	t=10;
	while(1)
	{
		cout<<"? "<<t<<endl;
		cin>>c;
		if (c=='N')
		{
			l=t/10+1;
			r=t-1;
			break;
		}
		else
		{
			cout<<"? "<<t-1<<endl;
			cin>>c;
			if (c=='Y') 
			{
				doit1(t-1);
				break;
			}
			else t*=10;
		}
	}
	while(l<=r)
	{
		mid=(l+r)/2;
		cout<<"? "<<mid*10<<endl;
		cin>>c;
		if (c=='Y') r=mid-1;
		else l=mid+1;
	}
	cout<<"! "<<l<<endl;
	return 0;
}