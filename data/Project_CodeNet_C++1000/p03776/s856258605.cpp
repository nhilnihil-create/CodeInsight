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
#define int long long
map<int, int> mp;

int C[51][51];

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, A, B;
    cin >> N >> A >> B;
    int v[51];
    rep(i, N) cin >> v[i];
    sort(v, v + N,greater<int>());
    int sum = 0;
    rep(i, A) sum += v[i];
    int S = sum;
    int same = 0;
    REP(i, A, B - 1) {
        if (sum * (i + 1)== A * (S + v[i])) {
            same++;
        }
        //cout << sum * (i + 1) << " " << A * (S + v[i])<< endl;
        S += v[i];
    }
    B = A + same;
    rep(i, N) mp[v[i]]++; 
    int ans = 0;
    int cnt = 0;
    int num = v[A - 1];
    rep(i, A) if (v[i] == num) cnt++;
    //cout << A << " " << B << " " << num << endl;
    rep(i, 51) C[0][i] = C[i][0] = 1;
    REP(i, 1, 50) {
        REP(j, 1, 50) {
            C[i][j] += C[i - 1][j];
            C[i][j] += C[i][j - 1];
        }
    }
    cout << fixed << setprecision(12) << (long double)sum/(A + 0.0) << endl;
    if (A == B) {
        //cout << mp[num] - cnt << " " << cnt << endl;
        cout << C[mp[num] - cnt][cnt] << endl;
    } else {
        REP(i, A, B) {
            ans += C[mp[num] - i][i];
            //cout << ans << endl;
        }
        cout << ans << endl;
    }
    

    return 0;
}
