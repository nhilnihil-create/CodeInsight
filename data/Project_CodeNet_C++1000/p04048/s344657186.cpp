#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define endl "\n"
#define gc getchar_unlocked
typedef long long ll;
typedef long double ld;
const double PI=acos(-1.0);
const int mod = 1000000007;




int main()
{
    FASTIO
	
	  ll n,x;
	  cin>>n>>x;
	  ll ans=3*(n-__gcd(n,x));
	  cout<<ans<<endl;

	return 0;
}


