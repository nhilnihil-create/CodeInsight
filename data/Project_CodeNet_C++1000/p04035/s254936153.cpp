//                             In The Name Of Allah                                           
//                             	Mohammad Hosseini
#include <bits/stdc++.h>
#define	ss second
#define ff first
#define use_fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ret(n) return cout << n, 0
#define se(n) cout << setprecision(n) << fixed
#define pb push_back
#define int long long
#define ld long double
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std; 

const int N = 1e5 + 100, OO = 1e9, T = 4500 + 100, M = 924844033, P = 6151, SQ = 280, lg = 30;
typedef pair <int, int> pii;
int a[N];

int32_t main() {
	use_fast;
	int n, l;
	cin >> n >> l;
	for(int i = 0; i < n; i++) 
		cin >> a[i];
	for(int i = 1; i < n; i++) {
		if(a[i] + a[i - 1] >= l) {
			cout << "Possible" << endl;
			for(int j = 0; j < i - 1; j++)
				cout << j + 1 << endl;
			for(int j = n - 2; j >= i; j--)
				cout << j + 1 << endl;
			cout << i << endl;
			return 0;
		}
	}
	cout << "Impossible" << endl;
	return 0;
}
/*
be carefull :
1- if not solve after 20 min, read again twice
2- after submit read the code again
3- fun with contest
4- uploaded by ubuntu 20.04 
5- ...
*/

