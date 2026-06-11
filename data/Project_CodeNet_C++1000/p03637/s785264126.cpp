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
	vector<int> a(n);
	REP(i,n) cin >> a[i];
	
	int c4=0,c2=0,odd=0;
	REP(i,n){
		if(a[i]%4==0) c4++;
		else if(a[i]%2==0) c2++;
		else odd++;
	}
	
	if(c4==n/2 && n - c4 == odd){
		cout << "Yes\n";
	}else if(odd > c4){
		cout << "No\n";
	}else{
		cout << "Yes\n";
	}
	
	return 0;
}