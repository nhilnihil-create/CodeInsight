#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
#include <tuple>
#include <math.h>
#include <set>
#include <map>
using namespace std ;
using ll = long long ;
using ld = long double ;
using vll = vector<ll> ;
using vvll = vector<vll> ;
using vc = vector<char> ;
using vvc = vector<vc> ;
using vb = vector<bool> ;
using vvb = vector<vb> ;
using pll = pair<ll,ll> ;
#define all(v) v.begin(),v.end() 
const ll INF = 1e18 ;
const ll mod = 1e9+7 ;
const double pie = acos(-1); 
vll dx4 = {-1,0,1,0} ;
vll dy4 = {0,-1,0,1} ;
vll dx8 = {-1,0,1,1,1,0,-1,-1} ;
vll dy8 = {-1,-1,-1,0,1,1,1,0} ; 

void fix_cout(){cout << fixed << setprecision(20) ; }
ll gcd(ll a,ll b){if(b==0) return a ; return gcd(b,a%b) ; }
ll lcm(ll a,ll b){return a/gcd(a,b)*b ; }
void chmax(ll &a,ll b){if(a<b) a = b ; }
void chmin(ll &a,ll b){if(a>b) a = b ; }

int main(){
	ll n ; cin >> n ;
	vll a(n) ;
	for(auto &i:a) cin >> i ;
	map<ll,ll> m ;
	ll pos = 0 ;
	vll b = a ;
	sort(all(b)) ;
	for(int i=0;i<n;i++) m[b.at(i)] = i ;
	ll ans = 0 ;
	for(int i=0;i<n;i++) ans += ((m[a.at(i)]&1)!=(i&1)) ;
	cout << ans/2 << endl ;
}