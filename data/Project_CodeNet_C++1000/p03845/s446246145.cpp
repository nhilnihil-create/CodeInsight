#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<int> t(n);
	rep(i,n) cin >> t[i];
	int m;
	cin >> m;
	vector<int> p(m);
	vector<int> x(m);
	rep(i,m) cin >> p[i] >> x[i];
	vector<int> ans(m);
	rep(i,m){
	int sum = 0;
	rep(j,n){
		if(j != p[i] - 1) sum += t[j];
	}	
	    sum += x[i];
		ans[i] = sum;
	}
	rep(i,m) cout << ans[i] << endl;
}