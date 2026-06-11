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
#define fast2 freopen ("badhair.gir","r",stdin);freopen ("badhair.cik","w",stdout);
#define mod 1000000007
#define fs(x,y) for(ll i=1;i<=y;i++) cin>>x[i]
#define fo(i,x,y) for(ll i=x;i<=y;i++)
#define INF 1000000000005
#define ull unsigned long long int
using namespace std;

ll n,m,ar[N],sum,t,tut[40];

void solve(int a,int b)
{
	// cout<<a<<sp<<b<<endl;
	if(a==b-1 || a*2<=b)
	{
		cout<<"Yes"<<endl;
		return;
	}
	cout<<"No"<<endl;

}

int main()
{
	fast;
	cin>>n;
	fs(ar,n);
	sort(ar+1,ar+n+1);
	if(ar[1]<ar[n]-1)
		return cout<<"No",0;
	if(ar[1]==ar[n])
	{
		solve(ar[1],n);
		return 0;
	}
	int a=0;
	fo(i,1,n-1)
	{
		a++;
		if(ar[i]!=ar[i+1])
			break;
	}
	if(a>ar[1])
		return cout<<"No",0;
	if((ar[n]-a)*2<=n-a)
		cout<<"Yes";
	else
		cout<<"No";

}

