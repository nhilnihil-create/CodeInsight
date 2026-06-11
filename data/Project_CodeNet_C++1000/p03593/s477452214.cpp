#include <iostream>
//#include <iomanip>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <utility>
//#include <set>
#include <map>
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
ll mod = 1000000007 ;
//long double pie = acos(-1) ;
//ll INF = 1000000000000 ;

void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

int main(){
	ll h,w ;
	cin >> h >> w ;
	map<char,ll> m ;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			char c ; cin >> c ;
			m[c]++ ;
		}
	}
	map<ll,ll> cnt ;
	for(auto p:m){
		cnt[0] += p.second/4 ;
		cnt[p.second%4]++ ;
	}
	if(h%2==0&&w%2==0){
		yorn(cnt[1]+cnt[2]+cnt[3]==0) ;
	}else if(h*w&1){
		yorn(cnt[1]+cnt[3]==1&&cnt[2]<=(h/2+w/2-cnt[3])) ;
	}else{
		yorn(cnt[1]+cnt[3]==0&&cnt[2]<=(h&1?w:h)/2) ;
	}
}
