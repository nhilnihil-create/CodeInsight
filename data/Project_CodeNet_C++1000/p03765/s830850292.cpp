#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
			re%=mod;
		}
		a=(a*a);
		a%=mod;
		b>>=1;
	}
	return re;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		string s,t;
		cin>>s>>t;
		int n=s.size(),m=t.size();
		int sc[n]={0},tc[m]={0};
		if(s[0]=='A')
		sc[0]=1;
		else
		sc[0]=-1;
		FOR(i,1,n)
		{
			if(s[i]=='A')
			sc[i]=sc[i-1]+1;
			else
			sc[i]=sc[i-1]-1;
		}
		if(t[0]=='A')
		tc[0]=1;
		else
		tc[0]=-1;
		FOR(i,1,m)
		{
			if(t[i]=='A')
			tc[i]=tc[i-1]+1;
			else
			tc[i]=tc[i-1]-1;
		}
		int q;
		cin>>q;
		int a,b,c,d,sd,td;
		FOR(i,0,q)
		{
			cin>>a>>b>>c>>d;
			sd=(sc[b-1]-(a==1?0:sc[a-2])+600000)%3;
			td=(tc[d-1]-(c==1?0:tc[c-2])+600000)%3;
			if(sd==td)
			cout<<"YES\n";
			else
			cout<<"NO\n";
		}
	}
	return 0;
}
