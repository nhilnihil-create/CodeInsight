#include "bits/stdc++.h"
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
    int N; cin >> N;
    pair<int, int> A[100010];
    rep(i, N) cin >> A[i].first;
    rep(i, N) A[i].second = i;
    sort(A, A + N);
    int ans[2] = {};
    rep(i, N){
        if(A[i].second % 2 != i % 2) ans[i % 2]++;
    }
    cout << ans[0] << endl;

    return 0;
}
// 2 1 4 3 5
//