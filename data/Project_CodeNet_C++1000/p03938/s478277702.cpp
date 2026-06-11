#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
#include <algorithm>
//#include <random>
#include <utility>
//#include <set>
//#include <map>
#include <queue>
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
using pll = pair<ll,ll> ;
#define all(v) v.begin(),v.end()
//ll mod = 1000000007 ;
//long double pie = acos(-1) ;
ll INF = 1ll<<61 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}
void chmax(ll &a,ll b){	if(a<b) a = b ;}
void chmin(ll &a,ll b){ if(a>b) a = b ;}

int main(){
	ll n ; cin >> n ;
	vll p(n) ;
	for(auto &i:p) cin >> i ;
	vll a(n),b(n) ;
	for(int i=0;i<n;i++) a.at(i) = (i+1)*30000 ;
	for(int i=1;i<=n;i++) b.at(n-i) = i*30000 ;
	for(int i=0;i<n;i++) a.at(p.at(i)-1) += i+1 ;
	for(int i=0;i<n;i++) cout << a.at(i) << (i==n-1?"\n":" ") ;
	for(int i=0;i<n;i++) cout << b.at(i) << (i==n-1?"\n":" ") ;
}
