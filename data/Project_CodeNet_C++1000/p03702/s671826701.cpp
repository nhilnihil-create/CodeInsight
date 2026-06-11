///A drunk man will find his way home, but a drunk bird may get lost forever...i
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair <int, int> pii;
#define pb push_back
#define pf push_front
#define f first
#define s second
#define sz(x) (int)x.size()
#define smin(x , y) x = min(x , y)
#define mp make_pair
const int mx = 1000 * 100;
int n, a, b;
int h[mx];
bool f(int x){
	int i = 0, ans = 0;
	while(h[i] > x * b){
		ans += ((h[i] - x * b) + a - b - 1) / (a - b);
		i++;
	}
	return (ans <= x);
}
int32_t main(){		
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	cin >> n >> a >> b;
	for(int i = 0; i < n; i++)
		cin >> h[i];
	sort(h , h + n , greater < int >());
	int l = 1, r = (h[0] + b - 1) / b, mid;
	while(r - l > 1){
		mid = (r + l) / 2;
		if(f(mid))
			r = mid;
		else
			l = mid;
	}
	cout << r << endl;
	return 0;
}
