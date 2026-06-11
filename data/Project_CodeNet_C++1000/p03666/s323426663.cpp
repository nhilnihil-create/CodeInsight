#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 3;
const int M = 1e6 + 7;
const long long MOD = 1e9;
const long long INF = 1e18 + 9;
const int SM = 1e3 + 5;
const int logN = 20, BL = 400;
const double EPS = 3e-16;

int main(){
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	long long n, a, b, c, d; cin >> n >> a >> b >> c >> d;
	
	long long diff = b - a;
	for(long long i = 0; i < n; i++){
		long long L = a + c * i, R = a + d * i;
		long long l = b + c * (n - i - 1), r = b + d * (n - i - 1);
		if(l <= R && L <= r){
			return cout << "YES", 0;
		}
	}
	
	cout << "NO";
	return 0;
}