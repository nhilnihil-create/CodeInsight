#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)
typedef long long ll;

int main(){
	vector<ll> e(3);
	rep(i, 3) cin >> e.at(i);
	sort(e.begin(), e.end());

	if (!(e[0] % 2 && e[1] % 2 && e[2] % 2)){ // if one of them is even
		cout << 0 << endl;
		return 0;
	}
	cout << e[0] * e[1] << endl;
}