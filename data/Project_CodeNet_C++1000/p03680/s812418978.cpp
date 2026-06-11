#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	int now = 1;
	bool ok = false;
	int counts = 0;
	rep(i,n){
		now = a[now-1];
		counts++;
		if(now == 2) {
			cout << counts << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}