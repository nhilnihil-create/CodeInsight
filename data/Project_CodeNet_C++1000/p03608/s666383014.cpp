#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <deque>
//#include <bitset>
//#include <math.h>
using namespace std ;
using ll = long long ;
//using ld = long double ;
using vll = vector<ll> ;
using vvll = vector<vll> ;
using vc = vector<char> ;
using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
using pll = pair<ll,ll> ;
#define all(v) v.begin(),v.end()
ll mod = 1000000007 ;
//long double pie = acos(-1) ;
ll INF = 1ll<<50 ;

void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
void fix_cout(){cout << fixed << setprecision(20) ;}
void chmax(ll &a,ll b){	if(a<b) a = b ;}
void chmin(ll &a,ll b){ if(a>b) a = b ;}

int main(){
	ll n,m,r ;
	cin >> n >> m >> r ;
	vll t(r) ;
	for(auto &i:t) cin >> i ;
	for(int i=0;i<r;i++) t[i]-- ;
	vvll d(n,vll(n,INF)) ;
	for(int i=0;i<n;i++) d[i][i] = 0 ;
	for(int i=0;i<m;i++){
		ll a,b,c ;
		cin >> a >> b >> c ;
		a-- ; b-- ;
		d[a][b] = d[b][a] = c ;
	}
	for(int k=0;k<n;k++) for(int i=0;i<n;i++) for(int j=0;j<n;j++) chmin(d[i][j],d[i][k]+d[k][j]) ;
	sort(all(t)) ;
	ll ans = INF ;
	do{
		ll sub = 0 ;
		for(int i=1;i<r;i++) sub += d[t[i-1]][t[i]] ;
		chmin(ans,sub) ;
	}while(next_permutation(all(t))) ;
	cout << ans << endl ;
}
