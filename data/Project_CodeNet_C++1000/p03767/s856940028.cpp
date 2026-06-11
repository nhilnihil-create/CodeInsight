#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int n;
	cin >> n;
	vector<int> a(3*n);
	rep(i, 3*n) cin >> a.at(i);

	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	long long ans = 0;
	rep(i, n)
		ans += a.at(i*2+1);
	cout << ans << endl;
	
}
