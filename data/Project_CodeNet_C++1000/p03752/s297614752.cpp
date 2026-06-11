#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
#include <algorithm>
//#include <utility>
//#include <set>
//#include <map>
//#include <queue>
//#include <deque>
#include <bitset>
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
//using pll = pair<ll,ll> ;
//#define all(v) v.begin(),v.end()
//ll mod = 1000000007 ;
//long double pie = acos(-1) ;
ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b%mod ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

int main(){
	ll n,k ;
	cin >> n >> k ;
	if(n==1){
		cout << 0 << endl ;
		return 0 ;
	}
	vll a(n) ;
	for(auto &i:a) cin >> i ;
	ll ans = INF ;
	for(int i=0;i<(1<<n);i++){
		bitset<20> bit(i) ;
		ll cost = 0 ;
		ll cnt = 1 ;
		ll pre = a.at(0) ;
		for(int j=1;j<n;j++){
			if(bit[j]){
				cost += max(pre+1-a.at(j),0LL) ;
				pre = max(pre+1,a.at(j)) ;
				cnt++ ;
			}else{
				if(pre<a.at(j)){
					cnt++ ;
					pre = a.at(j) ;
				}
			}
		}
		if(cnt>=k) ans = min(ans,cost) ;
	}
	cout << ans << endl ;
}
