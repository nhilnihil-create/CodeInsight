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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n){
		cin >> a[i];
		--a[i];
	}
	int cur = 0, cnt = 0;
	vector<bool> used(n, false);
	while(cur != 1){
		used[cur] = true;
		cur = a[cur];
		if(used[cur]){
			cout << -1 << endl;
			return 0;
		}
		++cnt;
	}
	cout << cnt << endl;
	return 0;
}