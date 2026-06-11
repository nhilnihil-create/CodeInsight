///A drunk man will find his way home, but a drunk bird may get lost forever...
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define int long long
#define sz(x) (int)x.size()
int a[2002], b[2002];
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int n, x, ans = 0, s;
	cin >> n >> x;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = a[i];
		ans += a[i];
	}
	for(int i = 1; i < n; i++){
		s = 0;
		for(int j = 0; j < n; j++){
			b[j] = min(b[j] , a[(j - i + n) % n]);
			s += b[j];
		}
		ans = min(ans , s + i * x);
	}
	cout << ans << endl;
	return 0;
}
