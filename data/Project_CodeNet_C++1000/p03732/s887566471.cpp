#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define MOD 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=0;lli w=0ll,weight=0ll,value=0ll,x=0ll,res=0ll;
    cin>>n>>w;
    vector<lli> a[4];
    for(int i=0;i<4;++i)
		a[i].pb(0);
    for(int i=0;i<n;++i)
    {
		cin>>weight>>value;
		if(i==0)
			x=weight;
		a[weight-x].pb(value);
	}
	for(int i=0;i<4;++i)
	{
		sort(a[i].begin()+1,a[i].end(),greater<lli>());
		for(int j=1;j<(int)a[i].size();++j)
			a[i][j]+=a[i][j-1];
	}
	for(int i=0;i<(int)a[0].size();++i)
	{
		for(int j=0;j<(int)a[1].size();++j)
		{
			for(int k=0;k<(int)a[2].size();++k)
			{
				for(int l=0;l<(int)a[3].size();++l)
				{
					if(x*i+(x+1)*j+(x+2)*k+(x+3)*l<=w)
						res=max(res,a[0][i]+a[1][j]+a[2][k]+a[3][l]);
				}
			}
		}
	}
	cout<<res<<endl;
}
