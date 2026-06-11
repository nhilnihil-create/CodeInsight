#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<vector<lli> > mat;
typedef vector<vector<bool> > matb;
typedef vector<string> vst;
typedef pair<lli,lli> pll;
typedef pair<double,double> pdd;
typedef vector<map<lli,lli>> graph;

vll a;
lli n;
lli sum = 0;
lli sum2 = 0;
lli ans = 1ll << 61;

int main(){
	cin >> n;
	a = vll(n);
	for(lli i = 0;i < n;i++){
		cin >> a[i];
	}
	for(lli i = 0;i < n;i++){
		sum += a[i];
	}
	sum -= a[0];
	sum2 += a[0];
	ans = abs(sum-sum2);
	for(lli i = 1;i < n-1;i++){
		sum -= a[i];
		sum2 += a[i];
		ans = min(ans,abs(sum-sum2));
	}
	cout << ans << endl;
	return 0;
}