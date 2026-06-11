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

const int N = 3e5 + 100, OO = 1e16, T = 4500 + 100, M = 1e9 + 7, P = 6151, SQ = 280, lg = 30;
typedef pair <int, int> pii;
int n, a[N];

bool check() {
	int od, ev, sum;
	od = ev = sum = 0;
	bool b = false;
	for(int i = 0; i < n; i++) {
		sum += a[i] - 1;
		if(a[i] == 1)
			b = true;
	}
	if(b) {
		if(sum % 2)
			return true;
		return false;
	}
	for(int i = 0; i < n; i++)
		od += (a[i] % 2), ev += ((a[i] + 1) % 2);
	if(ev % 2 == 1) 
		return true;
	if(od > 1)
		return false;
	int gc = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] % 2 == 1)
			a[i]--;
		gc = __gcd(a[i], gc);
	}
	for(int i = 0; i < n; i++)
		a[i] /= gc;
	return !check();
}

int32_t main() {
	use_fast;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	if(check()) 
		cout << "First" << endl;
	else
		cout << "Second" << endl;
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

