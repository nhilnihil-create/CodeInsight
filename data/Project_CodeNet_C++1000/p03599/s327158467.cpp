#include <iostream>
//#include <iomanip>
//#include <string>
//#include <vector>
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
//using vll = vector<ll> ;
//using vvll = vector<vll> ;
//using vc = vector<char> ;
//using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
//using pll = pair<ll,ll> ;
//#define all(v) v.begin(),v.end()
//ll mod = 1000000007 ;
//long double pie = acos(-1) ;
//ll INF = 100000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

int main(){
	ll a,b,c,d,e,f ;
	cin >> a >> b >> c >> d >> e >> f ;
	set<ll> w,s ;
	for(int i=0;i<=30;i++){
		if(100*a*i>f) break ;
		for(int j=0;j<=30;j++){
			if(100*(i*a+j*b)<=f) w.insert(100*(i*a+j*b)) ;
			else break ;
		}
	}
	for(int i=0;i<=3000;i++){
		if(i*c>f) break ;
		for(int j=0;j<=3000;j++){
			if(i*c+j*d<=f) s.insert(i*c+j*d) ;
			else break ;
		}
	}
	ll m1,m2;
	m1 = 100*a ;
	m2 = 0 ;
	for(auto i:w){
		if(i==0) continue ;
		for(auto j:s){
			if(i+j>f) continue ;
			if(100*j*(100+e)>(i+j)*100*e) continue ;
			if(100*m2*(i+j)<100*j*m1){
				m1 = i+j ;
				m2 = j ;
			}
		}
	}
	cout << m1 << " " << m2 << endl ;
}
