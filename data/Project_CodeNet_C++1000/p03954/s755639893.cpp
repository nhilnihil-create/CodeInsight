///A drunk man will find his way home, but a drunk bird may get lost forever...
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define int long long
#define sz(x) (int)x.size()
int b[2000 * 100 + 5], a[2000 * 100 + 5], n;
bool big(int x){
	for(int i = 1; i <= 2 * n - 1; i++)
		a[i] = (b[i] >= x);
	for(int i = 0; i < n - 1; i++){
		if((a[n - i] && a[n - i - 1]) || (a[n + i] && a[n + i + 1]))
			return 1;
		if((!a[n - i] && !a[n - i - 1]) || (!a[n + i] && !a[n + i + 1]))
			return 0;
	}
	return a[1];
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int ans = -1;
	cin >> n;
	for(int i = 1; i <= 2 * n - 1; i++)
		cin >> b[i];
	int l = 1, r = 2 * n - 1, mid;
	while(l <= r){
		mid = (r + l) / 2;
	//	cout << mid << " " << big(mid) << endl;
		if(big(mid)){
			ans = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}
