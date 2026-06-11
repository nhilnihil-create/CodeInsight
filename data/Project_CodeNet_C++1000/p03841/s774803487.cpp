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
int cnt[N], a[N], num[N], is[N];
bool mark[N];
deque <pii> v;

int32_t main() {
	use_fast;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		is[a[i]] = i;
		mark[a[i]] = true;
		v.pb({a[i], i});
	}	
	for(int i = 1; i <= n; i++)
		num[i] = n;
	sort(v.begin(), v.end());
	vector <int> t;
	for(int i = 1; i <= n * n; i++) {
		if(cnt[i] != 0) {
			if(num[cnt[i]] != 0)
				t.pb(cnt[i]);
			continue;
		}
		if((int)v.size() > 0) {
			while(cnt[i] == 0 && (int)v.size()) {
				pii p = v.front();
				num[p.ss]--;
				v.pop_front();
				if(num[p.ss] == n - p.ss) {
					if(p.ff == i) 
						if(num[p.ss])
							t.pb(p.ss);
					cnt[p.ff] = p.ss;
				}
				else {
					cnt[i] = p.ss;
					v.push_front(p);
					break;
				}
			}
		}
		if(cnt[i] == 0) {
			if((int)t.size() == 0)
				return cout << "No" << endl, 0;
			int h = t.back();
			if(num[h] == 1)
				t.pop_back();
			num[h]--;
			cnt[i] = h;
		}
		if(mark[i] && is[i] != cnt[i])
			return cout << "No" << endl, 0;
	}
	cout << "Yes" << endl;
	for(int i = 1; i <= n * n; i++)
		cout << cnt[i] << " ";
	cout << endl;
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

