#include<bits/stdc++.h>
#define DB(x)            cout << '>' << #x << ':' << x << endl;
#define DB2(x,y) 	     cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl;
#define rep(i,a,b)       for (ll i = a; i < b; i++)
#define repr(i,a,b)      for (ll i = a; i >= b; i--)
#define pb               push_back
#define F                first
#define S                second
#define mp               make_pair
#define MOD              1000000007
#define MAX              1e9
#define MIN              -1e9
#define vec(i)           vector<i>
#define PLL           	 pair<ll,ll>
#define mem(a,v)         memset(a,v,sizeof(a))
#define pf               printf
#define sc               scanf
#define _s               "%s"
#define _d               "%d"
#define _ll              "%lld"
#define _c               "%c"
#define FAST_IO          ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define min(a,b)         (a)>(b)?(b):(a)
#define max(a,b)         (a)>(b)?(a):(b)
#define all(c) 		     c.begin(),c.end()
typedef long long ll;
using namespace std;
int main()
{
	ll a=-1,b=-1;
	string s;
	cin>>s;
	rep(i,0,s.length())
	{
		if(i==0)
			continue;
		if(s[i]==s[i-1])
		{
			a=i,b=i+1;
			break;
		}
		if(i>1&&s[i]==s[i-2])
		{
			a=i-1,b=i+1;
			break;	
		}
	}
	cout<<a<<" "<<b;
    return 0;
}