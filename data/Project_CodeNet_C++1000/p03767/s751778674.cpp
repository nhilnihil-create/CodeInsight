#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
	int N;
	cin >> N;

	vector<int> a(N * 3);
	int64_t ans = 0;
	rep(i, N * 3) cin >> a.at(i);
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	rep2(i, N * 2, 1, 2) ans += a.at(i);
	cout << ans << endl;
}