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



int n, a[20202];
int x[20202], y[20202];
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(int i = 1; i <= n; i++){
		x[i] = i*20000;
		y[i] = (n-i)*20000;
	}
	
	for(int i = 1; i <= n; i++){
		y[a[i]] += i;
	}
	
	for(int i = 1; i <= n; i++){
		cout << x[i];
		if(i != n) cout << " ";
	}
	cout << endl;
	for(int i = 1; i <= n; i++){
		cout << y[i];
		if(i != n) cout << " ";
	}
	cout << endl;
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
