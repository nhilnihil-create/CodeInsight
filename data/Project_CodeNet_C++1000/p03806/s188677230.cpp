#include <iostream>
//#include <iomanip>
//#include <string>
//#include <vector>
#include <algorithm>
//#include <utility>
//#include <set>
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
ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

ll dp[41][410][410] ;

int main(){
	ll n,ma,mb ;
	cin >> n >> ma >> mb ;
	for(int i=0;i<=n;i++) for(int j=0;j<=400;j++) for(int k=0;k<=400;k++) dp[i][j][k] = INF ;
	dp[0][0][0] = 0 ;
	for(int i=1;i<=n;i++){
		ll a,b,c ;
		cin >> a >> b >> c ;
		for(int j=0;j<=400;j++){
			for(int k=0;k<=400;k++){
				dp[i][j][k] = min(dp[i][j][k],dp[i-1][j][k]) ;
				if(j>=a&&k>=b){
					dp[i][j][k] = min(dp[i][j][k],dp[i-1][j-a][k-b]+c) ;
				}
			}
		}
	}
	ll ans = INF ;
	for(int i=1;i*max(ma,mb)<=400;i++) ans = min(ans,dp[n][i*ma][i*mb]) ;
	cout << (ans==INF?-1:ans) << endl ;
}
