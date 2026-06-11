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

const int N = 3e5 + 100, OO = 724249387, T = 4500 + 100, M = 1e9 + 7, P = 6151, SQ = 280, lg = 30;
typedef pair <int, int> pii;
int a[N];

int32_t main() {
 	use_fast;
	int n, m, cnt = 0;
	cin >> m >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(a[i] % 2 == 1)
			cnt++;
	}
	if(cnt > 2)
		return cout << "Impossible" << endl, 0;
	if(m == 1) {
		cout << "1\n1\n1" << endl;
		return 0;
	}
	if(m == 2) {
		for(int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
		cout << 1 << endl << 2 << endl;
		return 0;
	}
	if(n == 1) {
		cout << a[0] << endl << 2 << endl << a[0] - 1 << " " << 1 << endl;
		return 0;
	}
	for(int i = 0; i < n; i++) {
		if(a[i] % 2 == 1) {
			swap(a[i], a[0]);
			break;
		}
	}
	for(int i = 1; i < n; i++) {
		if(a[i] % 2 == 1) {
			swap(a[i], a[n - 1]);
			break;
		}
	}
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	if(a[0] == 1)
		cout << n - 1 << endl;
	else
		cout << n << endl << a[0] - 1 << " ";
	for(int i = 1; i < n - 1; i++) 
		cout << a[i] << " ";
	cout << a[n - 1] + 1 << endl;
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
