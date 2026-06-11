#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <iomanip>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<long double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
#define INF 1LL<<60

int main() {
    ll mod = 1e9 + 7;
    int N;
    cin >> N;
    vector<ll> T(N), A(N);
    REP(i, N) cin >> T[i];
    REP(i, N) cin >> A[i];

    vector<bool> Tupdate(N, false), Aupdate(N, false);
    Tupdate[0] = true; Aupdate[N-1] = true;

    if(N==1) {
        if(T[0] == A[0]) {
            cout << 1 << endl;
            return 0;
        } else {
            cout << 0 << endl;
            return 0;
        }
    }
    
    FOR(i, 1, N-1) {
        if(T[i] > T[i-1]) Tupdate[i] = true;
    }

    FOR(i, 0, N-2) {
        if(A[i] > A[i+1]) Aupdate[i] = true;
    }

    REP(i, N) {
        if(Tupdate[i] && Aupdate[i] && T[i] != A[i]) {
            cout << 0 << endl;
            return 0;
        }
    }

    REP(i, N) {
        if( (!Tupdate[i] && Aupdate[i] && T[i] < A[i]) || (Tupdate[i] && !Aupdate[i] && T[i] > A[i])) {
            cout << 0 << endl;
            return 0;
        }
    }

    // if(Tmax != Amax) {
    //     cout << 0 << endl;
    //     return 0;
    // }

    ll ans = 1;
    REP(i, N) {
        if(!Tupdate[i] && !Aupdate[i]) {
            ans *= min(T[i], A[i]);
            ans %= mod;
        }
    }

    cout << ans << endl;

    return 0;
}