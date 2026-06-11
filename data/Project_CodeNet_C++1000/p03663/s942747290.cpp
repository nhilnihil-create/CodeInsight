#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define INF ((int)1e9)
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
ll p[20];
bool check(ll x) {
    char ans;
    cout << "? " << x << endl;
    fflush(stdout);
    cin >> ans;
    return (ans == 'Y');
}
ll actual = 100001;
bool check1(ll x) {
    if(actual <= x) return to_string(actual) <= to_string(x);
    if(actual > x) return to_string(actual) > to_string(x);
}
int main() {
    SYNC
    p[0] = 1; FOR(i,1,18) p[i] = p[i-1] * 10;
    int digits = 0;
    while(1) {
        if(!check(p[digits])) break;
        digits++;
        if(digits > 11) {
            ll z = 1;
            FOR0(i, 11) if(!check(p[i] + 1)) {z = p[i+1];}
            cout << "! " << z << endl; fflush(stdout);
            return 0;
        }
    }
    ll n = p[digits], x;
    FORD(i, 1, digits+1) {
        int l = (i == digits), r = 9; bool changed = false;
        while(l <= r) {
            int d = (l + r) >> 1;
            x = n + (d - ((n/p[i])%10))*p[i];
            if(!check(x)) { l = d+1; n = x; changed = true;}
            else r=d-1;
        }
        if(!changed) n = n + (1 - ((n/p[i])%10))*p[i];
    }
    cout << "! " << n/10 + 1<< endl;
    fflush(stdout);
    return 0;
}