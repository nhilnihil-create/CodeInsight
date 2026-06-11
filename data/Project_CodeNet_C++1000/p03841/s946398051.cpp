//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 200000 + 10;
const ll MOD = 1000000000 + 7;
const ll LOG = 25;

using ll = long long ;
using ld = long double ;
using vll = vector<ll> ;
using vvll = vector<vll> ;
using vc = vector<char> ;
using vvc = vector<vc> ;
using vb = vector<bool> ;
using vvb = vector<vb> ;
using pll = pair<ll,ll> ;
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
template<class T> void chmax(T &a,T b){if(a<b) a = b ; }
template<class T> void chmin(T &a,T b){if(a>b) a = b ; }
 
void solve(){
	ll n ; cin >> n ;
	vll ans(n*n,-1) ;
	ll pos = 0 ;
	vector<pll> a(n) ;
	for(int i=0;i<n;i++){
		cin >> a.at(i).first ;
		a.at(i).second = i+1 ;
		ans.at(a.at(i).first-1) = i+1 ;
	}
	sort(all(a)) ;
	for(int i=0;i<n;i++){
		for(int j=0;j<a.at(i).second-1;j++){
			while(ans.at(pos)!=-1) pos++ ;
			ans.at(pos) = a.at(i).second ;
		}
	}
	reverse(all(a)) ;
	pos = n*n-1 ;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-a.at(i).second;j++){
			while(ans.at(pos)!=-1) pos-- ;
			ans.at(pos) = a.at(i).second ;
		}
	}
	for(int i=0;i<n;i++){
		ll sub = a.at(i).second ;
		pos = -1 ;
		while(sub--){
			pos++ ;
			while(ans.at(pos)!=a.at(i).second) pos++ ;
		}
		if(pos+1!=a.at(i).first){
			cout << "No\n" ;
			return ;
		}
	}
	cout << "Yes\n" ;
	for(int i=0;i<n*n;i++) cout << ans.at(i) << (i==n*n-1?'\n':' ') ;
}
 
int main(){
	solve() ;
}