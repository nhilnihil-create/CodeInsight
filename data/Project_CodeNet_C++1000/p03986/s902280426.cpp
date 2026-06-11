#include<bits/stdc++.h>
using namespace std;
long long arr[1000000];
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    long long i,j,k,a,b,c,x,y,z,n,ans,mn;
	string s;
	cin>>s;
	n=s.length();
	for (i=0;i<n;i++)
	{
		if (s[i]=='S')
		{
			break;
		}
	}
	a=i;
	for (i=n-1;i>0;i--)
	{
		if (s[i]=='T')
		{
			break;
		}
	}
	b=i;
	ans=0;
	x=a+n-b-1;
	for (i=a;i<=b;i++)
	{
		if (s[i]=='S')
		{
			ans++;
		}
		else
		{
			ans--;
		}
		if (ans<0)
		{
			x=x+abs(ans);
			ans=0;
		}
	}
	x+=ans;
	cout<<x<<endl;
}