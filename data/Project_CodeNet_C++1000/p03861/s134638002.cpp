#include <bits/stdc++.h>
#define pb push_back
#define all(a) a.begin(),a.end()
#define forn(i,n) for(int i=0;i<int(n);i++)
#define forr(i,n) for(int i=int(n-1);i>=0;i--)
#define fora(i,a,b) for(int i=int(a);i<=int(b);i++)
#define forb(i,a,b) for(int i=int(a);i>=int(b);i--)
#define mod 1000000007
using namespace std;
using ll=long long int;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<ll> vii;
typedef pair<ll ,ll> pii;
ll get(ll a,ll k)
{
	//if(a==0)return 1;
	return a/k;
}
void solve()
{
	ll a,b,k;
	cin>>a>>b>>k;
	if(a==0)
	{
		cout<<b/k+1<<endl;
		return;
	}
	ll x=max(a-1,0LL);
	cout<<get(b,k)-get(x,k)<<endl;
}

int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    int t=1;
   // cin>>t;
    while(t--)
	solve();
    return 0;
}
