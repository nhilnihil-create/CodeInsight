#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007

ll ceil1(ll a,ll b)
{	if(a%b==0)
		return a/b;
	else
		return a/b+1;}


void solve()
{
	int n,m,w1,w2,cnt=0;
	cin>>n>>m;
	string arr1[n],arr2[m];
	for(int i=0;i<n;i++)
		cin>>arr1[i];
	for(int i=0;i<m;i++)
		cin>>arr2[i];
	w1=arr1[0].size();
	w2=arr2[0].size();
	for(int j=0;j+m<=n;j++)				
		for(int i=0;i+w2<=w1;i++)		
			{
				cnt=0;
				for(int k=0;k<m;k++)
					for(int l=0;l<w2;l++)
						if(arr1[j+k][i+l]==arr2[k][l])
							cnt++;
				if(cnt==m*w2)
				{
					cout<<"Yes";
					return;
				}
			}
	cout<<"No";
	return;
}

int main()
{
	fast;
	ll q=1;
	// cin>>q;
	while(q--)
		solve();
	return 0;
}

