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



int n, m;
string s[111];
int c[26];
void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s[i];
		for(int j = 0; j < m; j++){
			c[s[i][j]-'a']++;
		}
	}
	
	bool ok = 1;
	int cnt = 0;
	for(int i = 0; i < 26; i++){
		if(c[i] & 1) cnt++;
	}
	if(cnt > 1 || (cnt == 1 && n*m%2==0)) ok = 0;
	cnt = 0;
	for(int i = 0; i < 26; i++){
		if(c[i] % 4 == 2) cnt++;
	}
	if(n&1) cnt -= m/2;
	if(m&1) cnt -= n/2;
	if(cnt > 0) ok = 0;
	
	cout << (ok ? "Yes" : "No") << endl;
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
