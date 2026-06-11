#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 60)
#define PI 3.14159265358979

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



i64 n, a[101010], m;
i64 d[101010];
void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		d[i+1] = d[i]+a[i];
	}
	
	bool ok = 0;
	for(int i = 2; i <= n; i++){
		if(d[i]-d[i-2] >= m){
			ok = 1;
			cout << "Possible" << endl;
			for(int j = 1; j < i-1; j++){
				cout << j << endl;
			}
			for(int j = n-1; j >= i; j--){
				cout << j << endl;
			}
			cout << i-1 << endl;
			break;
		}
	}
	if(!ok){
		cout << "Impossible" << endl;
	}
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
