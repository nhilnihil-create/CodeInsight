///A drunk man will find his way home, but a drunk bird may get lost forever...
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define int long long
#define sz(x) (int)x.size()
pair < int , int > a[1000 * 100 + 5];
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int n, ans = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i].f;
		a[i].s = i;
	}
	sort(a , a + n);
	for(int i = 0; i < n; i++)
		if(a[i].s % 2 != i % 2)
			ans++;
	cout << ans / 2 << endl;
	return 0;
}
