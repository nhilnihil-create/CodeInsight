#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
	int n;cin >> n;
	vector <int> v(3*n);
	rep(i,3*n) cin >> v[i];
	sort(v.begin(), v.end());
	int64_t ans=0;
	rep(i,n){
		ans+=v[3*n-2*(i+1)];
	}
	cout << ans << endl;
}
