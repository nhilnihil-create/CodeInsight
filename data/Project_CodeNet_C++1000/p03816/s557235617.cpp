#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int n;
	cin >> n;
	map<int,int> a;
	REP(i,n){
		int input;
		cin >> input;
		a[input]++;
	}

	ll b=0;
	for(auto x: a){
		b += x.second - 1;
	}
	
	if(b%2==0){
		cout << a.size() << endl;
	}else{
		cout << a.size()-1 << endl;
	}
	
	return 0;
}