#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define MP make_pair
#define MEM(i,j) memset(i,j,sizeof i)
#define Tie ios::sync_with_stdio(0),cin.tie(0);
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n,k,tmp,ans;
pll a[110000];
bitset<110000> b;

int main()
{Tie
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i].first>>a[i].second;
	for(int i=1<<30;1;i>>=1)
	{
		if(!i||(i&k))
		{
			tmp=0;
			for(int j=0;j<n;j++)
				if(!b[j]&&(i&a[j].first)==0)
					tmp+=a[j].second;
			ans=max(ans,tmp);
		}
		else
			for(int j=0;j<n;j++)
				if(a[j].first&i)
					b[j]=1;
		if(!i)break;
	}
	cout << ans<<'\n';
}
