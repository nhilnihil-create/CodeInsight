#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int n;

int main(void){
	cin >> n;
	vector<int> a(n);
	rep(i, n){
		cin >> a[i];
		a[i]--;
	}
	lli ans = 0;
	rep(i, n){
		if(i == a[a[i]]) ans++;
	}
	cout << ans/2 << endl;
	return 0;
}
