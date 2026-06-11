#include <bits/stdc++.h>
using namespace std;

#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

signed main(){
	int n;
	cin >> n;
	int memo[100010] = {};
	int a[100010];
	for(int i = 0;i < n;i++){
		cin >> a[i];
		a[i]--;
	}
	int now = 0;
	int cnt = 0;
	while(1){
		if(memo[now]) break;
		if(now == 1){
			cout << cnt << endl;
			return 0;
		}
		memo[now] = 1;
		now = a[now];
		cnt++;
	}
	cout << -1 << endl;
	return 0;
}
