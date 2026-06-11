#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main() {
	int n,t=0;
	ll r1=0,r2=0;
	cin >> n;

	vector<int> a(n);
	rep(i,n)
		cin >> a.at(i);

	rep(i,n) {
		t += a.at(i);

		if(i%2==0 && t<=0) {
			r1 += abs(-t)+1;
			t = 1;
		} else if(i%2 && t>=0) {
			r1 += t+1;
			t = -1;
		}
	}

	t = 0;
	rep(i,n) {
		t += a.at(i);

		if(i%2 && t<=0) {
			r2 += abs(-t)+1;
			t = 1;
		} else if(i%2==0 && t>=0) {
			r2 += t+1;
			t = -1;
		}
	}

	cout << min(r1,r2) << endl;
}