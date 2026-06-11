#include<bits/stdc++.h>
using namespace std;
long long arr[1000000];
set <long long int> s1,s2,s3;
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    long long n,a,b,c,x,y,z,i,j,k,t,ans,m;
    cin>>n;
    for (i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
	ans=0;
	x=1;
	for (i=0;i<n;i++)
	{
		if (arr[i]>x)
		{
			if (arr[i]%x==0)
			{
				ans=ans+ (arr[i]/x) -1;
				if (x==1)
				{
					x++;
				}
			}
			else
			{
				ans=ans+ (arr[i]/x);
			}
		}
		else if (arr[i]==x)
		{
			x++;
		}
		else
		{
			continue;
		}
	}
	cout<<ans<<endl;
}