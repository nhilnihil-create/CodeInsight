#ifdef _DEBUG
#include "MyLib.h"
#else
#define main_D main
#include "bits/stdc++.h" 
#include <regex>
#define _USE_MATH_DEFINES
#include <math.h>
#define FOR(i,s,e) for (int i = int(s); i < int(e); ++i)
#define REP(i,e) FOR(i,0,e)
#define INF (INT_MAX/2)
#define EPS (1.0e-8)
#define LINF (LLONG_MAX/2)
const int MGN = 8;
const int ARY_SZ_MAX = 10000000;
using namespace std;
using ll = long long; using ull = unsigned long long;
using vi = vector<int>; using vvi = vector<vi>; using vvvi = vector<vvi>;
using vb = vector<bool>; using vvb = vector<vb>; using vvvb = vector<vvb>;
using vl = vector<ll>; using vvl = vector<vl>;
using vd = vector<double>; using vs = vector<string>;
using pii = pair<int, int>; using pll = pair<ll, ll>;
// functions
template <typename T>
using priority_queue_lo = priority_queue<T, vector<T>, greater<T>>;
#endif


int main_D() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;  cin >> N;
    vl A(N*3);
    REP(i, N*3) cin >> A[i];

    priority_queue_lo<ll> pql;
    ll sum1 = 0;
    REP(i, N) {
        pql.push(A[i]);
        sum1 += A[i];
    }

    priority_queue<ll> pq;
    ll sum2 = 0;
    FOR(i, N*2, N*3) {
        pq.push(A[i]);
        sum2 += A[i];
    }

    vl sumL(N+1,0);
    sumL[0] = sum1;
    FOR(k,N,2*N) {
        pql.push(A[k]);
        sum1 += A[k];
        sum1 -= pql.top();
        sumL[k-N+1] = sum1;
        pql.pop();
    }

    vl sumR(N+1,0);
    sumR[N] = sum2;
    for (int k = 2 * N - 1; k >= N; k--) {
        pq.push(A[k]);
        sum2 += A[k];
        sum2 -= pq.top();
        sumR[k-N] = sum2;
        pq.pop();
    }

    ll ans = -LINF;
    REP(i,N+1) {
        ans = max(ans, sumL[i] - sumR[i]);
    }

    cout << ans << endl;

    return 0;
}