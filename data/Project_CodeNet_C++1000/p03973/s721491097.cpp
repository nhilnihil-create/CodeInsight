///A drunk man will find his way home, but a drunk bird may get lost forever...
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define int long long
#define sz(x) (int)x.size()
int a[1000 * 100 + 5];
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int n, k = 1, ans = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] == k){
			k++;
			continue;
		}
		if(a[i] < k)
			continue;
		ans += (a[i] - 1) / k;
		if(k == 1)
			k++;
	}
	cout << ans << endl;
	return 0;
}
