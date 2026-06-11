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
#define for0(i,n)        for(int i=0;i<n;i++)
#define for1(i,n)        for(int i=1;i<=n;i++)
#define forab(i,a,b)       for(int i=a;i<=b;i++)
#define lcm(a, b)     ((a)*((b)/gcd(a,b)))
#define sq(a)		   (a)*(a)
#define nw				"\n"
#define abs(x)		fabs(x)
#define pcase(z,x)    cout<<"Case "<<z<<": "<<x<<"\n"
#define mod	1000000007
#define N	1005
bool prime[1005];
void sieve(){
	memset(prime,1,sizeof(prime));
	for(ll p=2 ; p*p<=N ; p++){
		for(ll i=p*p ; i<=N ; i+=p){
			prime[i] = 0;
			}
		}
	}
ll exp(ll n, ll p){
	ll x=p,cnt=0;
	while((n/x)>0){
		cnt = (cnt + n/x)%mod;
		x *= p;
		}
	return cnt%mod;
	}
ll cal_fac(ll n){
	ll x,ans=1;
	for(ll i=2 ; i<=n ; i++){
		if(prime[i]==1){
			x = exp(n,i);
			x += 1;
			ans = (ans*x)%mod;
			}
		}
	return ans%mod;
	}
int main()
{
	sieve();
	ll n,ans;
	cin>>n;
	ans = cal_fac(n);
	ans%=mod;
	if(ans<0) ans += mod;
	cout<<ans<<nw;
	
	return 0;
}