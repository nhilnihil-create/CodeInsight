///A drunk man will find his way home, but a drunk bird may get lost forever...
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair <int, int> pii;
#define pb push_back
#define f first
#define s second
#define sz(x) (int)x.size()
const int mx = 1000 * 100 + 5;
int a[mx], w[mx];
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	int n, l, t, x = 0;
	cin >> n >> l >> t;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> w[i];
		if(w[i] == 1){
			if(t >= l - a[i])
				x += 1 + (t - (l - a[i])) / l;
			a[i] = (a[i] + t) % l;
		}
		else{
			if(t > a[i])
				x -= 1 + (t - a[i] - 1) / l;
			a[i] = ((a[i] - t) % l + l) % l;
		}
	}
	sort(a , a + n);
	x = (x % n + n) % n;
	for(int i = x; i < n; i++)
		cout << a[i] << endl;
	for(int i = 0; i < x; i++)
		cout << a[i] << endl;
	return 0;
}
