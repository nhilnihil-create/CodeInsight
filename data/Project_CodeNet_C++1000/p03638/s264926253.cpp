#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 60)

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



int h,w, n, a[101010];
void solve(){
	cin >> h >> w;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	int x = 0, y = 0;
	int ans[101][101];
	for(int i = 0; i < n; i++){
		while(a[i]--){
			ans[x][y] = i+1;
			if(x&1) y--;
			else y++;
			if(y == w){
				x++;
				y = w-1;
			}
			if(y == -1){
				x++;
				y = 0;
			}
		}
	}
	
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cout << ans[i][j];
			if(j != w-1) cout << " ";
		}
		cout << endl;
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
