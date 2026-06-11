#include <iostream>
//#include <iomanip>
#include <string>
//#include <vector>
//#include <algorithm>
//#include <utility>
//#include <set>
//#include <map>
//#include <queue>
//#include <deque>
//#include <bitset>
//#include <math.h>
using namespace std ;
//using ll = long long ;
//using ld = long double ;
//using vll = vector<ll> ;
//using vvll = vector<vll> ;
//using vc = vector<char> ;
//using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
//using pll = pair<ll,ll> ;

//ll mod = 1000000007 ;
//long double pie = acos(-1) ;

//string yorn(bool a){if(a) return"Yes" ; return "No" ;}
//string YorN(bool a){if(a) return"YES" ; return "NO" ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}

bool same(string t,int s,int g){
	char c = t.at(s) ;
	for(int i=s;i<=g;i++){
		if(t.at(i)!=c) return false ;
	}
	return true ;
}

int main(){
	string s ; cin >> s ;
	int n = s.size() ;
	int ans = 1000000 ;
	for(char c='a';c<='z';c++){
		bool ok = false ;
		for(int i=0;i<n;i++){
			if(s.at(i)==c) ok = true ;
		}
		if(!ok) continue ;
		string t = s ;
		int sub = 0 ;
		for(int i=0;i<n;i++){
			if(same(t,0,n-1-sub)) break ;
			sub++ ;
			for(int j=0;j<n-sub;j++){
				if(t.at(j+1)==c) t.at(j) = c ;
			}
		}
		if(ans>sub) ans = sub ;
	}
	cout << ans << endl ;
}
