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

ll n,m,ar[N],sum,t;

vector<int> ans;

int main()
{
	fast;
	cin>>m>>n;
	// cout<<endl;
	fs(ar,n);
	int flag=0;
	fo(i,1,n)
		if(ar[i]%2==1)
			flag++;
	if(flag>2)
		return cout<<"Impossible",0;
	if(ar[1]==1 && n==1)
	{
		cout<<1<<endl<<1<<endl<<1;
		return 0;
		// return cout<<1,0;
	}
	// sort(ar+1,ar+n+1);
	int k=1;
	fo(i,1,n)
	{
		if(ar[i]%2==1)
		{
			k=i+1;
			ans.pb(ar[i]);
			break;
		}
	}
	fo(i,1,n)
		if(ar[i]%2==0)
			ans.pb(ar[i]);
	fo(i,k,n)
		if(ar[i]%2==1)
			ans.pb(ar[i]);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<sp;

	cout<<endl;
	if(n==1)
		ans.pb(0);
	if(ans[0]-1<=0)
		t++;
	cout<<ans.size()-t<<endl;
	if(ans[0]-1>0)
	cout<<ans[0]-1<<sp;
	for(int i=1;i<ans.size()-1;i++)
		cout<<ans[i]<<sp;
	cout<<ans[ans.size()-1]+1;

}



/*     cd onedrive\desktop\kod
cls

Sinav:21-22 aralik
Aciklama: Muhtemelen 25 aralik
*/