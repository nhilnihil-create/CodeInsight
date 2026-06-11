//                             In The Name Of Allah
#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

#define ss second
#define ff first
#define use_fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ret(n) return cout << n, 0
#define se(n) cout << setprecision(n) << fixed
#define pb push_back
#define int long

using namespace std; 
 
const int N = 1e5 + 1100, OO = 1e9 + 7, M = 1e9 + 7, P = 769, sq = 360, lg = 23;
typedef pair <int, int> pii; 
int num[N], a[N];

int32_t main() {
    use_fast;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		num[a[i]]++;
	}
	sort(a, a + n);
	if(n == 1)
		return cout << "Impossible", 0;
	if(n == 2) {
		if(num[1] == 2)
			return cout << "Possible", 0;
		return cout << "Impossible", 0;
	} 
	for(int i = 0; i <= a[n - 1]; i++) {
		if(num[max(i, a[n - 1] - i)] == 0)
			return cout << "Impossible", 0;
		num[max(i, a[n - 1] - i)]--;
	}
	int mid = (a[n - 1] + 1) / 2 + 1;
	for(int i = 0; i < mid; i++) 
		if(num[i])
			return cout << "Impossible", 0;
	cout << "Possible" << endl;
	return 0;	
} 
/*
be carefull :
1- if not solve after 20 min, read again twice
2- after submit read the code again
3- fun with contest
4- ... 
*/
