#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int k, s;
	cin >> k >> s;
	int ans = 0;
	for(int x = 0; x <= k; ++x){
		for(int y = 0; y <= k; ++y){
			int z = s - x - y;
			if(0 <= z && z <= k) ++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
