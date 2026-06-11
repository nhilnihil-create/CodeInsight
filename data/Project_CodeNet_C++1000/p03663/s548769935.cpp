#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cassert>
#include <cstring>
using namespace std;

#define GET_ARG(a,b,c,F,...) F
#define REP3(i,s,e) for (i = s; i <= e; i++)
#define REP2(i,n) REP3 (i,0,(int)(n)-1)
#define REP(...) GET_ARG (__VA_ARGS__,REP3,REP2) (__VA_ARGS__)
#define RREP3(i,s,e) for (i = s; i >= e; i--)
#define RREP2(i,n) RREP3 (i,(int)(n)-1,0)
#define RREP(...) GET_ARG (__VA_ARGS__,RREP3,RREP2) (__VA_ARGS__)
#define DEBUG(x) cerr << #x ": " << x << endl

typedef long long ll;

bool query(ll n) {
    cout << "? " << n << endl;
    string res;
    cin >> res;
    return res == "Y";
}

bool answer(int n) {
    cout << "! " << n << endl;
}

int main(void) {
    int len = 10;
    for (int x = 1e9-1; x > 0; x /= 10, len--) {
        if (!query(x)) break;
    }
    if (len == 1) {
        for (long long x = 10; x <= 1e9; x *= 10, len++) {
            if (!query(x)) break;
        }
        if (len == 10) {
            answer(1);
            return 0;
        }
    }
    ll l = pow(10,len-1)-1;
    ll r = pow(10,len)-1;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        if (query(m * 10))
            r = m;
        else
            l = m;
    }
    answer(r);
    return 0;
}