#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 62)

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



i64 a,b,c,d,e,f,g;
void solve(){
	cin >> a >> b >> c >> d >> e >> f >> g;
	
	i64 ans = 0;
	
	if(a&&d&&e){
		if((a%2)+(d%2)+(e%2) >= 2){
			ans += 3;
			a--;
			d--;
			e--;
		}
	}
	ans += (a/2)*2;
	ans += b;
	ans += (d/2)*2;
	ans += (e/2)*2;
	
	cout << ans << endl;
}

int main(){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
