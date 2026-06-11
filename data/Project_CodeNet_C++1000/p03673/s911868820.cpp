#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> b;
	int p = 1;
	rep(i,n) {
		int a;
		cin >> a;
		if (p == 1) b.push_back(a);
		else b.insert(b.begin(), a);
		p *= -1;
	}

	if ( p == 1) rep(i, n) cout << b[i] << endl;
	else rep(i, n) cout << b[n-1-i] << endl;

return 0;
}