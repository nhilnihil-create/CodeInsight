#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int inf = 1012345678;
#define REP(i, a, b) for(ll i = ll(a); i <= ll(b); i++)
ll range_btw_nums(ll a,ll b)
{
	ll cnt=0;
	REP(i,a,b)
	{
		cnt++;
	}
	return cnt;
}
int main()
{
	ll a,b;
	cin>>a>>b;
	if(a<0 && b>0)
		cout<<"Zero";
	else if(a==0 || b==0)
		cout<<"Zero";
	else if(a>0 && b>0)
		cout<<"Positive";
	else if(a<0 && b<0)
	{
		if(range_btw_nums(a,b)%2==0)
			cout<<"Positive";
		else if(range_btw_nums(a,b)%2!=0)
			cout<<"Negative";
	}
	//cout<<endl;
	//cout<<"range "<<range_btw_nums(a,b);
}