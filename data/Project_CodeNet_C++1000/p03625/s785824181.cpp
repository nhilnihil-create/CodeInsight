#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 62)
#define PI 3.14159265358979

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



int n, a[101010];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a,a+n,greater<int>());
	
	i64 cnt = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == a[i+1]){
			if(cnt != 0){
				cout << cnt*a[i] << endl;
				return;
			}
			cnt = a[i];
			i++;
		}
	}
	cout << 0 << endl;
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