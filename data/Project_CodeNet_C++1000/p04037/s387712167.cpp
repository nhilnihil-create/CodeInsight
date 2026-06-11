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
using namespace std;

ll n,m,ar[N],sum,t;



int main()
{
	fast;
	cin>>n;
	fs(ar,n);
	sort(ar+1,ar+n+1,greater<int>());
	int l=0;
	for(int i=1;i<=n;i++)
	{
		l=i;
		if(ar[i+1]<=i)
		{
			l=i;
			break;
		}
	}
	ll t1=0,t2=0;
	t1=ar[l]-l;
	for(int i=l+1;i<=n;i++)
	{
		if(ar[i]<l)
			break;
		t2++;
	}
	// cout<<l<<endl;
	// cout<<t1<<sp<<t2<<endl;
	if(t2%2==0 && t1%2==0)
		cout<<"Second";
	else
		cout<<"First";

}



/*     cd onedrive\desktop\kod
cls

Sinav:21-22 aralik
Aciklama: Muhtemelen 25 aralik
*/