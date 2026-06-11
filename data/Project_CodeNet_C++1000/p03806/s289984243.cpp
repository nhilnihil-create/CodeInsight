#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
#include <algorithm>
#include <utility>
//#include <set>
#include <map>
//#include <queue>
//#include <deque>
#include <bitset>
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

//ll mod = 1000000007 ;
//long double pie = acos(-1) ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void mysort(vector<string> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}

ll INF = 1000000000000 ;

struct drug{
	int a ;
	int b ;
	int c ;
};

int main(){
	ll n,ma,mb ;
	cin >> n >> ma >> mb ;
	vector<pair<ll,ll>> must ;
	ll sub1=ma,sub2=mb ;
	while(ma<=10*n&&mb<=10*n){
		must.push_back(make_pair(ma,mb)) ;
		ma += sub1 ;
		mb += sub2 ;
	}
	vector<drug> fr,ba ;
	for(int i=0;i<n;i++){
		drug d ;
		cin >> d.a >> d.b >> d.c ;
		if(i&1){
			ba.push_back(d) ;
		}else{
			fr.push_back(d) ;
		}
	}
	map<pair<ll,ll>,ll> m1,m2 ;
	pair<ll,ll> ins ;
	for(int i=0;i<(1<<fr.size());i++){
		bitset<25> bit(i) ;
		ll a = 0,b = 0 ;
		ll cost = 0 ;
		for(int j=0;j<fr.size();j++){
			if(bit[j]){
				a += fr.at(j).a ;
				b += fr.at(j).b ;
				cost += fr.at(j).c ;
			}
		}
		ins.first = a ;
		ins.second = b ;
		if(m1.count(ins)){
			m1[ins] = min(m1[ins],cost) ;
		}else{
			m1[ins] = cost ;
		}
	}
	for(int i=0;i<(1<<ba.size());i++){
		bitset<25> bit(i) ;
		ll a = 0,b = 0 ;
		ll cost = 0 ;
		for(int j=0;j<ba.size();j++){
			if(bit[j]){
				a += ba.at(j).a ;
				b += ba.at(j).b ;
				cost += ba.at(j).c ;
			}
		}
		ins.first = a ;
		ins.second = b ;
		if(m2.count(ins)){
			m2[ins] = min(m2[ins],cost) ;
		}else{
			m2[ins] = cost ;
		}
	}
	ll ans = INF ;
	pair<ll,ll> serch ;
	for(auto p:m1){
		ll a = p.first.first ;
		ll b = p.first.second ;
		ll c = p.second ;
		bool ok = false ;
		for(int i=0;i<must.size();i++){
			if(a>must.at(i).first||b>must.at(i).second) continue ;
			serch.first = must.at(i).first-a ;
			serch.second = must.at(i).second-b ;
			if(m2.count(serch)){
				ok = true ;
				ll cost = c+m2[serch] ;
				ans = min(ans,cost) ;
			}
		}
	}
	if(ans==INF) cout << -1 << endl ;
	else cout << ans << endl ;
}
