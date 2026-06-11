#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define ld long double
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define mp make_pair
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll H,W,h,w,i,j,a;
	cin>>H>>W>>h>>w;
	if(H%h==0 && W%w==0)
	{
		cout<<"No";
		return 0;
	}
	cout<<"Yes\n";
	for(i=1;i<=H;i++)
	{
		for(j=1;j<=W;j++)
		{
			if(j%w==0 && i%h==0)
			{
				a=-1000*(w*h-1)-1;
			}
			else
			{
				a=1000;
			}
			cout<<a<<" ";
		}
		cout<<endl;
	}
	return 0;
}