#include <bits/stdc++.h>
using namespace std;

#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

signed main(){
	int n;
	cin >> n;
	int a[100010];

	for(int i = 0;i < n;i++) cin >> a[i];

	int wari = 2;
	int ans = a[0]-1;

	for(int i = 1;i < n;i++){
		if(wari == a[i]){
			wari++;
		}else{
			int tmp = a[i] - (wari-1);
			ans += tmp / wari;
			a[i] -= tmp / wari * wari;
			if(a[i] > wari) ans++;
		}
	}
	cout << ans << endl;

	return 0;
}
