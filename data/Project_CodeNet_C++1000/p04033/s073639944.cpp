#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	string ans;
	if(a >= 0 && b >= 0) ans = "Positive";
	else if(a < 0 && b >= 0) ans = "Zero";
	else{
		a = -a;
		b = -b;
		if((a-b)%2 == 0) ans = "Negative";
		else ans = "Positive";
	}
	cout << ans << endl;
	return 0;
}