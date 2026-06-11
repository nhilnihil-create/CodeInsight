#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, P;
    cin >> N >> P;
    int A[51];
    rep(i, N) cin >> A[i];
    ll ans = 0;
    ll cnt0 = 0;
    ll cnt1 = 0;
    rep(i, N) if(A[i] % 2 == 0) cnt0++;
    cnt1 = N - cnt0;
    if(cnt0 == N) {
        if(P == 1)
            cout << 0 << endl;
        else
            cout << (1LL << cnt0) << endl;
        return 0;
    }
    cnt1--;
    cout << (1LL << cnt0) * (1LL << cnt1) << endl;


    return 0;
}
