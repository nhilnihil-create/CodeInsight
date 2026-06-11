#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, a, b) for(ll i = ll(a); i <= ll(b); i++)
int main()
{
	ll n,x=0,max_x=0;
	cin>>n;
	string s;
	cin>>s;
	REP(i,0,s.size()-1)
	{
		if(s[i]=='I')
			x++;
		else if(s[i]=='D')
			x--;
		max_x=max(x,max_x);
	}	
	cout<<max_x;
}