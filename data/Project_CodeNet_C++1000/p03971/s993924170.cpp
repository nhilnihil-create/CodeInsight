#include<iostream>
#include<string>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
#include<set>
#include<utility>
#include<iterator>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
//#define t ll t;cin>>t;while(t--)
#define nn cout<<endl;
#define ff(a,n) for(ll i=a;i<n;i++)
#define cY cout<<"YES\n"
#define cN cout<<"NO\n"
#define cy cout<<"Yes\n"
#define cn cout<<"No\n"
#define sc second
#define fs first
#define c(a) cout<<a<<endl

void solve()
{
	ll n,a,b; cin>>n>>a>>b;
	string s; cin>>s;
	ll j=0, f=0;
	for(auto x:s)
	{
		if(x=='c')cn;
		else if(j+f<a+b)
		{
			if(x=='a')
			{
				cy;
				j++;
			}
			else if(x=='b'&&f<b)
			{
				cy;
				f++;
			}
			else cn;
		}
		else cn;
	}
}

int main()
{
	solve();
}
/*



*/