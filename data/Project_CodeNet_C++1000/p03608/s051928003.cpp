#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
#include <algorithm>
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
ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

int main(){
	ll n,m,r ;
	cin >> n >> m >> r ;
	vll town(r) ;
	for(auto &i:town) cin >> i ;
	sort(all(town)) ;
	vector<vector<pll>> g(n,vector<pll>(0)) ;
	for(int i=0;i<m;i++){
		ll a,b,c ;
		cin >> a >> b >> c ;
		a-- ; b-- ;
		g.at(a).emplace_back(b,c) ;
		g.at(b).emplace_back(a,c) ;
	}
	vvll d(n,vll(n,INF)) ;
	queue<ll> q ;
	for(int i=0;i<n;i++){
		d.at(i).at(i) = 0 ;
		q.push(i) ;
		ll p ;
		while(!q.empty()){
			p = q.front() ;
			q.pop() ;
			for(int j=0;j<g.at(p).size();j++){
				if(d.at(i).at(g.at(p).at(j).first)>d.at(i).at(p)+g.at(p).at(j).second){
					d.at(i).at(g.at(p).at(j).first) = d.at(i).at(p)+g.at(p).at(j).second ;
					q.push(g.at(p).at(j).first) ;
				}
			}
		}
	}
	ll ans = INF ;
	do{
		ll sub = 0 ;
		for(int i=0;i<r-1;i++) sub += d.at(town.at(i)-1).at(town.at(i+1)-1) ;
		ans = min(ans,sub) ;
	}while(next_permutation(all(town))) ;
	cout << ans << endl ;
}
