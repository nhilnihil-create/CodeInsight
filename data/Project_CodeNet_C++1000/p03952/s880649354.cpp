//                             In The Name Of Allah                                           
//                             	Mohammad Hosseini
#include <bits/stdc++.h>
#define	ss second
#define ff first
#define use_fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ret(n) return cout << n, 0
#define se(n) cout << setprecision(n) << fixed
#define pb push_back
//#define int long long
#define ld long double
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std; 

const int N = 3e5 + 100, OO = 1e9, T = 4500 + 100, M = 1e9 + 7, P = 6151, SQ = 280, lg = 30;
typedef pair <int, int> pii;
int ans[N], us[N];

int32_t main() {
	use_fast;
	int n, x;
	cin >> n >> x;
	if(x == 1 || x ==  2 * n - 1)
		return cout << "No" << endl, 0;
	ans[n - 1]=x;
	us[x] = true;
	int l = 1, d = 1, r = 2 * n - 1;
 	cout << "Yes" << endl;
    for(int i = 1 ; i < n; i++){
       	while(us[l])
			l++;
        while(us[r])
			r--;
        us[l] = true;
        us[r] = true;
        ans[n -1 + i * d] = l;
         ans[n -1 - i * d] = r;
    	d *= -1;
	}
   	for(int i = 0; i < 2 * n - 1; i++)
    	cout << ans[i]<< endl;
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

