#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
#include <algorithm>
//#include <utility>
#include <set>
//#include <map>
//#include <queue>
//#include <deque>
//#include <bitset>
//#include <math.h>
using namespace std ;
using ll = long long ;
//using ld = long double ;
using vll = vector<ll> ;
using vvll = vector<vll> ;
//using vc = vector<char> ;
//using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
//using pll = pair<ll,ll> ;
#define all(v) v.begin(),v.end()
//ll mod = 1000000007 ;
//long double pie = acos(-1) ;
//ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

int main(){
	ll n,m ;
	cin >> n >> m ;
	vvll a(n,vll(m)) ;
	for(auto &i:a) for(auto &j:i) cin >> j ;
	for(int i=0;i<n;i++) a.at(i).push_back(0) ;
	vector<bool> use(m+1,true) ;
	ll ans = 0 ;
	vll cnt(m+1,0) ;
	ll rem = m ;
	for(int i=0;i<n;i++) cnt.at(a.at(i).at(0))++ ;
	for(int i=1;i<=m;i++) ans = max(ans,cnt.at(i)) ;
	for(int i=1;i<=m;i++){
		if(cnt.at(i)>=ans){
			use.at(i) = false ;
			rem-- ;
			cnt.at(i) = 0 ;
		}
	}
	vll pos(n,0) ;
	while(rem){
		for(int i=0;i<n;i++){
			if(use.at(a.at(i).at(pos.at(i)))==false){
				while(use.at(a.at(i).at(pos.at(i)))==false) pos.at(i)++ ;
				cnt.at(a.at(i).at(pos.at(i)))++ ;
			}
		}
		ll sub = 0 ;
		for(int i=1;i<=m;i++) sub = max(sub,cnt.at(i)) ;
		ans = min(ans,sub) ;
		for(int i=1;i<=m;i++){
			if(cnt.at(i)>=ans){
				use.at(i) = false ;
				rem-- ;
				cnt.at(i) = 0 ;
			}
		}
	}
	cout << ans << endl ;
}
