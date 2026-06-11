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
	ll m ; cin >> m ;
	vll a(n) ;
	for(int i=0;i<n;i++){
		cin >> a.at(i) ;
	}
	for(int i=1;i<n;i++){
		if(a.at(i)+a.at(i-1)>=m){
			cout << "Possible\n" ;
			for(int j=1;j<=i-1;j++) cout << j << endl ;
			for(int j=n-1;j>=i+1;j--) cout << j << endl ;
			cout << i << endl ;
			return 0 ;
		}
	}
	cout << "Impossible\n" ;
}


