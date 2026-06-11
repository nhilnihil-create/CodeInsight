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

ll n,m,ar[N],sum,t,ilu[N],ilu2[N];

stack<int> st;

void pre()
{
	for(int i=n;i>=1;i--)
	{
		while(st.size() && ar[st.top()]>ar[i])
			st.pop();
		if(!st.size())
			ilu[i]=n+1;
		else
			ilu[i]=st.top();
		st.push(i);
	}
	while(st.size())
		st.pop();
	for(int i=1;i<=n;i++)
	{
		while(st.size() && ar[st.top()]>=ar[i])
			st.pop();
		if(!st.size())
			ilu2[i]=0;
		else
			ilu2[i]=st.top();
		st.push(i);
	}
}

int main()
{
	fast;
	cin>>n;
	fs(ar,n);
	pre();
	// fo(i,1,n)
	// cout<<ilu[i]<<sp<<ilu2[i]<<endl;
	fo(i,1,n)
		sum+=(ilu[i]-i)*(i-ilu2[i])*ar[i];
	cout<<sum;

}



/*     cd onedrive\desktop\kod
cls

Sinav:21-22 aralik
Aciklama: Muhtemelen 25 aralik
*/