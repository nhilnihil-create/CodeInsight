#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	vector<ll> a(3);
	rep(i,3) cin >> a[i];
	sort(a.begin(),a.end());
	if(a[2]%2 == 0) cout << 0 << endl;
	else cout << a[0]*a[1] << endl;
}