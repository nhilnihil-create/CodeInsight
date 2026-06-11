#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int n, m;

int main(void){
	cin >> n;
	vector<lli> t(n);
	lli total = 0;
	rep(i, n){
		cin >> t[i];
		total += t[i];
	}
	cin >> m;
	rep(i, m){
		int p;
		lli x;
		cin >> p >> x;
		p--;
		cout << total-t[p]+x << endl;
	}
	return 0;
}
