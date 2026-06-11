
// Problem : A - BBQ Easy
// Contest : AtCoder - AtCoder Grand Contest 001
// URL : https://atcoder.jp/contests/agc001/tasks/agc001_a
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
const long long int  modu=1e9+7;
#define endl '\n'
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define inp(x)  for(auto &t:x) cin>>t;
#define itr     vector<int>::iterator
#define debug(a) cout << #a << "=" << a << ' '<<endl;
#define out(x)  for(auto &t:x) cout<<t<<" "; cout<<endl;
#define ff first
#define ss second
#define pb push_back
#define initialize(a,v)  for(int i=0;i<a.size();++i) a[i]=v;
#define all(x) x.begin(),x.end()
#define mpt(mp) for(auto it=mp.begin();it!=mp.end();it++)
#define trav(x) for(int i=0;i<(int)x.size();++i)
#define mkp(a,b) make_pair(a,b)
#define sz(x)  (int)x.size()

int noofdig(int N)
{
	return floor(log10(N))+1;
}


ll f(ll a)
{

return 0;

}



void pre()
{

}



void solve()
{
	int n;
	cin>>n;
	ll ans=0;
	vi a(2*n);
	inp(a)
	sort(all(a));
	
	for(int i=0;i<2*n;i+=2)
	{
		ans+=min(a[i],a[i+1]);
		
	}
	
	cout<<ans<<endl;
	







}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
}
