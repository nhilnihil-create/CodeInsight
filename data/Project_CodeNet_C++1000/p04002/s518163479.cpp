#include<iostream>
using namespace std;
#include<set>
#define int long long int
#define mod 1000000007
int power(int a,int b)
{
	if(b==0)
	    return 1;
	if(b==1)
	    return a;
	else 
	{
		if(b%2==0)
		{
			int r=power(a,b/2);
			r=r*r;
			return r;
		}
		else
		{
			int r=power(a,b/2);
			r=r*r;
			r=r*a;
			return r;
		}
	}
}
int32_t main()
{
	int h,w,n;
	cin>>h>>w>>n;
    int total=(h-2)*(w-2);
    int value[10]={0};
    multiset<pair<int,int>> s;
    int j;
    for(j=0;j<n;j++)
    {
		int x,y;
		cin>>x>>y;
		s.insert({x,y});
	}
    for(auto p:s)
    {
		int x=p.first;
		int y=p.second;
		int i;
		for(i=x-2;i<=x;i++)
		{
			for(j=y-2;j<=y;j++)
			{
				if(i>=1&&i<=h-2&&j>=1&&j<=w-2)
				{
					int a,b;
					int count=0;
					for(a=i;a<=i+2;a++)
					{
						for(b=j;b<=j+2;b++)
						{
							auto it=s.find({a,b});
							if(it!=s.end())
							   count++;
						}
					}
					value[count]++;
				}
			}
		}
	}
	int sum=0;
	for(j=1;j<=9;j++)
	{
		value[j]/=j;
	}
	for(j=1;j<=9;j++)
	   sum+=value[j];
	value[0]=total-sum;
	for(j=0;j<10;j++)
	    cout<<value[j]<<endl;
}
