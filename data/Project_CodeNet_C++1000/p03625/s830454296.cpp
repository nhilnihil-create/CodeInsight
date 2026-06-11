//#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<utility>
#include<algorithm>
#include<cstring>
#include<sstream>
#include <iomanip>

using namespace std;

typedef long long ll ;
typedef double db;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector< pair<int,int> > vii;
const double pi = 2*acos(0) ;

#define pf		  	printf
#define sf			  scanf
#define pb(a)         push_back(a)
#define mp			make_pair
#define fi			 first
#define se			 second
#define for0(i,n)        for(ll i=0;i<n;i++)
#define for1(i,n)        for(int i=1;i<=n;i++)
#define forab(i,a,b)       for(int i=a;i<=b;i++)
#define lcm(a, b)     ((a)*((b)/gcd(a,b)))
#define sq(a)		   (a)*(a)
#define nw				"\n"
#define abs(x)		fabs(x)
#define pcase(z,x)    cout<<"Case "<<z<<": "<<x<<"\n"
int main()
{
	ll n,p,t;
	cin>>n;
	map<ll,ll>m;
	for0(i,n){
		cin>>p;
		m[p]++;
		}
	ll x=0,y=0;
	for(auto it:m){
		if(it.se>=2){t=it.fi ; x = max(x,t); }
		}
	m[x] -= 2;
	for(auto it:m){
		if(it.se>=2){t=it.fi; y = max(y,t);}
		}
	ll ans = x*y;
	cout<<ans<<nw;
	
	return 0;
}