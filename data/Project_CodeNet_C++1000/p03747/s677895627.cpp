#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define F first
#define S second
#define pb push_back
const ll N = 1e6 + 10, MOD =  1e9 + 7, INF = 1e18;
const long double PI = acos(-1);
int n, len, t, xD;
vector <int> all;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> len >> t;
	for (int i = 0; i < n; i++){
		int dir, pos;
		cin >> pos >> dir;
		if (dir == 2) dir = -1;
		all.pb(((pos + dir * t) % len + len) % len);
		if (dir == 1){
			xD = (xD + (pos + t) / len) % n;
		}
		if (dir == -1){
			xD = ((xD - (len - pos + t - 1) / len) % n + n) % n;
		}
	}
	sort(all.begin(), all.end());
	for (int i = 0; i < n; i++){
		cout << all[(i + xD) % n] << '\n';
	}
    return 0;
}