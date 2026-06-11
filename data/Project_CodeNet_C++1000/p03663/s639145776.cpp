#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iomanip>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair
#define mt make_tuple

bool check(ll n) {
    cout << "? " << n << endl << flush;
    string ans;
    cin >> ans;
    return (ans == "Y");
}

int main(void)
{
    // cin.sync_with_stdio(false);
    ll MAX = 1000000000;
    if (check(MAX * 10)) {
        ll query = MAX / 10;
        bool found = false;
        while(query >= 1) {
            if (check(query + 1)) {
                query /= 10;
            }
            else {
                found = true;
                break;
            }
        }
        ll ans = 1;
        if (found) ans = query * 10;
        cout << "! " << ans << endl << flush;
        return 0;
    }


    ll query = 1;
    while(1) {
        if (check(query)) {
            query *= 10;
        }
        else break;
    }
    
    ll lo = query;
    ll hi = query * 10 - 1;
    while(lo < hi) {
        ll k = (lo + hi) / 2;
        if (check(k)) {
            hi = k;
        }
        else {
            lo = k + 1;
        }
    }
    cout << "! " << lo / 10 << endl << flush;

    return 0;
}
