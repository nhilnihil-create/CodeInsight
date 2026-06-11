#include <bits/stdc++.h>
#define N 1000005
#define ll long long int 	
#define MP make_pair
#define pb push_back
#define ppb pop_back
#define sp " "
#define endl "\n"
#define fi first
#define se second
#define ii pair<int,int>
#define lli pair<ll,ll>
#define fast cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define fast2 freopen ("1_23.txt","r",stdin);
#define mod 1000000007
#define fs(x,y) for(ll i=1;i<=y;i++) cin>>x[i]
#define fo(i,x,y) for(ll i=x;i<=y;i++)
#define INF 1000000000005
using namespace std;

ll n,m,ar[N],sum,t;

vector<int> v[N];

int f(int ind,int back)
{
	int k=0;
	for(int i=0;i<v[ind].size();i++)
		k=max(k,f(v[ind][i],ind));
	// cout<<ind<<sp<<k<<endl;
	if(k==m-1 && ind!=1 && back!=1)
	{
		sum++;
		return 0;
	}
	// if(back==1 && k==m && ind!=1)
	// {
	// 	sum++;
	// 	return 0;
	// }
	return k+1;

}

int main()
{
	fast;
	cin>>n>>m;
	fs(ar,n);
	if(ar[1]!=1)
		sum++;
	fo(i,2,n)
		v[ar[i]].pb(i);
	f(1,1);
	cout<<sum<<endl;
}



/*     cd onedrive\desktop\kod
cls

Sinav:21-22 aralik
Aciklama: Muhtemelen 25 aralik
*/