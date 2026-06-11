#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k, x, y;
	cin >> n >> k >> x >> y;
	
	if (n < k){
		cout << x*n;
	}
	else{
		cout << x*k + y*(n-k);
	}

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}