#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//#include "atcoder/all"
//using namespace atcoder;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	int nn = 2*n - 1;
	if(x <= 1 || nn <= x){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	vector<int> ans(nn, 0);
	ans[n-2] = x-1;
	ans[n-1] = x;
	ans[n] = x+1;
	int cnt = 1;
	rep(i,nn){
		if(ans[i] > 0) continue;
		while(x-1 <= cnt && cnt <= x+1) ++cnt;
		ans[i] = cnt++;
	}
	rep(i,nn) cout << ans[i] << endl;
	return 0;
}
