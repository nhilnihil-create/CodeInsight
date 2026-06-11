#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main() {
	ll N,T,t,p,c=0,r=0;
	cin >> N >> T;

	cin >> p;
	rep(i,N-1) {
		cin >> t;
		if(t-p > T) {
			r += p-c+T;
			c = t;
		}
		p = t;
	}

	cout << r+p-c+T << endl;
}