#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
#include <algorithm>
#include <utility>
//#include <set>
//#include <map>
//#include <queue>
//#include <deque>
//#include <bitset>
//#include <math.h>
using namespace std ;
using ll = long long ;
//using ld = long double ;
using vll = vector<ll> ;
//using vvll = vector<vll> ;
//using vc = vector<char> ;
//using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
using pll = pair<ll,ll> ;
#define all(v) v.begin(),v.end()
//ll mod = 1e9+7 ;
//long double pie = acos(-1) ;
//ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

int main(){
	ll w,h ;
	cin >> w >> h ;
	vll p(w),q(h) ;
	for(auto &i:p) cin >> i ;
	for(auto &i:q) cin >> i ;
	vector<pll> r ;
	for(int i=0;i<w;i++) r.emplace_back(p.at(i),0) ;
	for(int i=0;i<h;i++) r.emplace_back(q.at(i),1) ;
	ll a=0,b=0 ;
	sort(all(r)) ;
	ll ans = 0 ;
	for(int i=0;i<w+h;i++){
		if(r.at(i).second){
			ans += r.at(i).first*(w+1-a) ;
			b++ ;
		}else{
			ans += r.at(i).first*(h+1-b) ;
			a++ ;
		}
	}
	cout << ans << endl ;
}
