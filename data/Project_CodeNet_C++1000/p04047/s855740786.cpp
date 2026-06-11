#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int N;
	cin >> N;
	priority_queue<int> L;
	rep(i, 2 * N) {
		int l;
		cin >> l;
		L.push(l);
	}
	int ans = 0;
	rep(i,N) {
		L.pop();
		ans += L.top();
		L.pop();
	}
	cout << ans << endl;
	return 0;
}