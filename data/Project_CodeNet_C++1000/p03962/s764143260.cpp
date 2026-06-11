#include<iostream>
#include<cmath>
#include<vector>
#include<climits>
#include<algorithm>
#include<numeric>
#include<iomanip>
#include<map>
#include<set>
#include<random>
#include<cassert>
using namespace std;
#define ll long long int
#define ld long double
const ll Mod = 1000000007;
ll CaseN=1;
const ld PI = 22/7.0;

bool mycmp(string s,string t)
{
if(s.size()<t.size())
{
return true;	
}		
return false;
}


void solve()
{
  set<ll> s;
  for(ll i=0;i<3;i++)
  {
	 ll x;
	 cin>>x;
	 s.insert(x); 
	}
 cout<<s.size();
 // cout<<"Case #"<<CaseN<<": ";
   CaseN++;
	// print your ans below;
    
return ;
}


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
	//cin>>t;
	while(t--)
	{
	solve();	
	}
}
