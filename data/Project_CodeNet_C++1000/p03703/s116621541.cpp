#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
#include <algorithm>
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
ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

const int MAX = 2000000 ;

//宣言するときはstaticをつけて静的変数にするかグローバル変数として宣言
class SGT{
public :
	int n ;
//	d変数は単位元、計算の邪魔をしない値に設定する、INFや0など
	int d = 0 ;
	int num[MAX] ;

	void init(vector<ll> &a){
		n = 1 ;
		while(a.size()>n) n *= 2 ;
		for(int i=0;i<n;i++){
			if(i<a.size()) num[n-1+i] = a.at(i) ;
			else num[n-1+i] = d ;
		}
		for(int i=n-2;i>=0;i--){
			num[i] = num[i*2+1]+num[i*2+2] ;
		}
	}

//	内容次第でwhile内の計算式を書き換える
	void update(int i,int a){
		i += n-1 ;
		num[i] = a ;
		while(i>0){
			i = (i-1)/2 ;
			num[i] = num[i*2+1]+num[i*2+2] ;
		}
	}

	int query(int a,int b,int l,int r,int now){
		if(r<=a||b<=l) return d ;
		if(a<=l&&r<=b) return num[now] ;
		int r1 = query(a,b,l,(l+r)/2,now*2+1) ;
		int r2 = query(a,b,(l+r)/2,r,now*2+2) ;
		return r1+r2 ;
	}
};

int main(){
	ll n,k ;
	cin >> n >> k ;
	vll a(n) ;
	for(auto &i:a) cin >> i ;
	vll sum(n+1,0) ;
	for(int i=1;i<=n;i++) sum.at(i) += sum.at(i-1)+a.at(i-1)-k ;
	vll sub = sum ;
	sort(all(sub)) ;
	map<ll,ll> m ;
	ll pre = INF ;
	ll cnt = 0 ;
	for(int i=0;i<sub.size();i++){
		if(sub.at(i)!=pre) m[sub.at(i)]=cnt,cnt++ ;
		pre = sub.at(i) ;
	}
	vll zero(m.size(),0) ;
	zero.at(m[0]) = 1 ;
	static SGT sgt ;
	sgt.init(zero) ;
//	for(int i=0;i<sgt.n;i++) cout << sgt.num[i+sgt.n-1] << " " ; cout << endl ;
	ll ans = 0 ;
	for(int i=1;i<sum.size();i++){
		ans += sgt.query(0,m[sum.at(i)]+1,0,sgt.n,0) ;
//		cout << sum.at(i) << " " << sgt.query(0,m[sum.at(i)]+1,0,sgt.n,0) << endl ;
//		cout << m[sum.at(i)] << endl  ;
//		cout << sgt.query(0,1,0,sgt.n,0) << " " << sgt.query(0,2,0,sgt.n,0) << endl ;
//		for(auto p:m) cout << p.first << "(" << sgt.num[p.second+sgt.n-1] << ") " ; cout << endl ;
		sgt.update(m[sum.at(i)],sgt.num[m[sum.at(i)]+sgt.n-1]+1) ;
//		cout << ans << endl ;
	}
	cout << ans << endl ;
//	for(auto p:m) cout << p.first << " " << p.second << endl ;
}
