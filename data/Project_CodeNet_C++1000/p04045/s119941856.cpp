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
vector<bool> like(11,1);
int n;
int s;
int ans=1e9;
void go(int cur,bool first)
{
	if(cur>=n)
	{
		ans=min(cur,ans);
		return;
	}
	forn(i,10)
	{
		if(i==0&&first)continue;
		if(like[i])
		{
			go(cur*10+i,0);
		}
	}
}
void solve()
{
	cin>>n;
	string p=to_string(n);
	s=p.size();
	int k;
	cin>>k;
	forn(i,k)
	{
		int a;
		cin>>a;
		like[a]=0;
	}
	go(0,1);
	cout<<ans<<endl;
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
