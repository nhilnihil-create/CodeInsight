//============================================================================
// Name        : template.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <set>
#include <vector>
#include <string.h> // for memset in CF judge.
using namespace std;
#define _CRT_SECURE_NO_DEPRECATE // suppress some compilation warning messages (for VC++ users)
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
// To simplify repetitions/loops, Note: define your loop style and stick with it!
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define forn(i,n) \
for (int i =0; i<(n); i++)
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000 // 2 billion
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
//memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table
//memset(arr, 0, sizeof arr); // useful to clear array of integers

// ll fc(int n) {
//   if(n == 1) return 1;
//   return n * fc(n-1);
// }
// int main() {
//   int n; cin >>n;
//   ll fd = fc(n);
//   // cout << "fd os " << fd << endl;
//   int sv[fd+1]; int ans = 0;
//   for(ll i = 1; i<=fd; i++) {
//     if(sv[i] == 1 || fd % i != 0) continue;
    
//     sv[i] = 1;
//     sv[fd/i] = 1;
//     ll rv = ans + 2;
//     ans =  rv % (ll) (10e9 + 7); 
//     // cout << "ans increment" << ans << endl;
//   }
//   cout << ans << endl;
//   return 0;
// }

	int main() {
		int n, a, b;
		cin >> n >> a >> b;
		int x[n];
		forn(i,n) cin >> x[i];
        ll ans = 0;
        REP(i,0, n-2) {
         ans +=  min((ll) (x[i+1] - x[i]) * a, (ll) b);
        }
        cout << ans <<endl;
		return 0;
	}
