/*
First solve the problem,then write the code.
Author-Manas Singh(@manassingh557)
*/

// #pragma GCC optimize ("Ofast")
// #pragma GCC optimization("O3")
// #pragma GCC optimization("unroll-loops")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
// #pragma GCC optimize ("-ffloat-store")

#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define mod 1000000007
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define endl "\n"

#define mii map<int,int>
#define mll map<ll,ll>
#define pii pair<int,int>
#define pll pair<<ll,ll>
#define vii vector<int>
#define vll vector<ll>

#define rep(i,end) for(int i=0;i<end;i++)
#define repi(i,start,end) for(int i=start;i<=end;i++)
#define repd(i,start,end) for(int i=start;i>=end;i--)

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

using namespace std;

int main()
{
	fast;
	int n;
	cin>>n;
	ll ans=1;
	repi(i,2,n)
	{
	    ans=((ans%mod)*(i%mod))%mod;
	}
	cout<<ans<<endl;
	return 0;
}