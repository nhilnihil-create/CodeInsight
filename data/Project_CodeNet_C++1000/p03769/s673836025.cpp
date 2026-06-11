#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef vector<ll> vl;
const int MN = 105;
int main() {
	ll n;
	cin >> n;
	n++;
	vl bu;
	vl res;
	while(n) {
		bu.push_back(n&1);
		n >>= 1;
	}
	reverse(bu.begin(),bu.end());
	res.push_back(1);
	int lo = 0,hi = 2;
	for(int i=1;i<bu.size();i++) {
		if(i > 1) {res.push_back(hi);hi++;}
		if(bu[i]) {
			res.push_back(lo);lo--;}
	}
	for(int i=0;i<res.size();i++) {
		res[i] -= lo;
	}
	int sz = res.size();
	for(int i=0;i<sz;i++) {
		res.push_back(i+1);
	}
	cout << res.size() << '\n';
	for(int i=0;i<res.size();i++) {
		if(i > 0) {cout << " ";}
		cout << res[i];
	}
	cout << '\n';
}
