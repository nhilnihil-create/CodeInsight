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

const int N = 1e5 + 100, OO = 100, T = 10, M = 100, P = 6151, SQ = 280, lg = 30;
typedef pair <int, int> pii;
int a[N];

int32_t main() {
	use_fast;
    string s; 
	cin >> s;
    vector<int> cnt(4, 0);
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] == 'N') 
			cnt[0]++;
        if(s[i] == 'S') 
			cnt[1]++;
        if(s[i] == 'W') 
			cnt[2]++;
        if(s[i] == 'E') 
			cnt[3]++;
    }
    if(cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0 && cnt[3] > 0) 
        return cout << "Yes" << endl, 0;
    if(cnt[0] > 0 && cnt[1] > 0 && cnt[2] == 0 && cnt[3] == 0) 
        return cout << "Yes" << endl, 0;
    if(cnt[0] == 0 && cnt[1] == 0 && cnt[2] > 0 && cnt[3] > 0) 
        return cout << "Yes" << endl, 0;
       
    cout << "No" << endl;
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

