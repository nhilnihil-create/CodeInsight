#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	ll N, A, B;
	cin >> N >> A >> B;
	ll ans = B*(N-1) + A - B - A*(N-1) + 1;
	ans = max(ans, (ll)0);
	cout << ans << endl;
	return 0;
}
