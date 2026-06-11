#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	string s;
	cin >> s;
	
	int n = (int)s.size();
	int i=n;

	while(i > 0){
		if(i-7 >= 0 && s.substr(i-7,7)=="dreamer"){
			i -= 7;
		}else if(i-5 >= 0 && s.substr(i-5,5)=="dream"){
			i -= 5;
		}else if(i-6 >= 0 && s.substr(i-6,6)=="eraser"){
			i -= 6;
		}else if(i-5 >= 0 && s.substr(i-5,5)=="erase"){
			i -= 5;
		}else{
			cout << "NO\n";
			return 0;
		}
	}
	
	cout << "YES\n";
	
	
	return 0;
}