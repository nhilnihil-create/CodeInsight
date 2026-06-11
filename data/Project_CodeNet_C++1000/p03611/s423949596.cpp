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
	sort(a.begin(),a.end());
	vector<int> d(100000,0);
	rep(i,n){
		d[a[i]]++;
	}
	int ans = 0;
	for(int i = 2; i < 100000; i++){
		ans = max(d[i] + d[i-1] + d[i-2],ans);
	}
	cout << ans << endl;
}