#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, a, b) for(ll i = ll(a); i <= ll(b); i++)
int main()
{
	ll a,b,c,x,tmp,cnt=0;
	string alpha,s;
	alpha=" abcdefghijklmnopqrtsuvwxyz";
	cin>>s;
	vector<char> v;
	REP(i,1,alpha.size()-1)
	{
		ll f=0;
		REP(i,1,alpha.size()-1)
		{
			bool found=false;
			REP(j,0,s.size()-1)
			{
				if(s[j]==alpha[i])
					found=true;
			}
			if(found==false)
			{
				cout<<alpha[i];
				return 0;
			}
		}
	}
	cout<<"None";
}