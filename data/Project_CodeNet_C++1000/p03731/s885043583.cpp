// Confessions of a Dangerous Mind

/*
	"We know what we are, but know not what we may be."
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 3;
const int M = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long INF = 1e18 + 9;
const int SM = 1e3 + 5;
const int logN = 20, BL = 400;
const double EPS = 3e-16;

/*
	"You never know how strong you are until being strong is the only choice you have."
*/

int main(){
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

/*
	"With self-discipline most anything is possible."
*/

	long long n, t; cin >> n >> t;
	
	long long ans = t;
	vector<long long> a(n);
	for(long long i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(long long i = 0; i < n - 1; i++){
		long long x1 = a[i], y1 = a[i] + t, x2 = a[i + 1], y2 = a[i + 1] + t;
		if(x2 < y1){
			ans += x2 - x1;	
		}
		else {
			ans += t;
		}
	}
	
	cout << ans;
	return 0;
}

/*
	"Reach for it. Push yourself as far as you can."
*/