#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int X;
	cin >> X;
	int pos = 0;
	int ans = 1;
	while (true) {
		pos += ans;
		if (pos >= X) {
			cout << ans << endl;
			return 0;
		}
		ans++;
	}
	return 0;
}