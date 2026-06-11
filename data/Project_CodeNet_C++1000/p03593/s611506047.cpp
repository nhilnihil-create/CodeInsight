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



int h, w;
string a[111];
int cnt[26];
void solve(){
	cin >> h >> w;
	for(int i = 0; i < h; i++){
		cin >> a[i];
		for(int j = 0; j < w; j++){
			cnt[a[i][j]-'a']++;
		}
	}
	
	int b = (h%2)*(w%2), c = (h%2)*w/2 + (w%2)*h/2;
	for(int i = 0; i < 26; i++){
		if(cnt[i] == 0) continue;
		if(cnt[i]%2 == 1){
			b--;
			cnt[i]--;
		}
		if(cnt[i]%4 == 2){
			c--;
			continue;
		}
	}
	if(b < 0 || c < 0) cout << "No" << endl;
	else cout << "Yes" << endl;
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
