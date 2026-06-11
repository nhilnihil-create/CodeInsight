#include<bits/stdc++.h>
using namespace std;

#define lint long long
#define P pair<int, int>
#define LLP pair<long long, long long>
#define REP(i, x, n) for(int i = (x), i##_len = (int)(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = (int)(n) ; i < i##_len ; ++i)
#define repr(i, n) for(int i = (int)(n) - 1 ; i >= 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())
#define SORT_INV(x) sort((x).rbegin(), (x).rend())

const int IINF = 1e9 + 100;
const long long LLINF = 2e18 + 129;
const long long MOD = 1e9 + 7;
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
const double EPS = 1e-8;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<lint> x(n), y(m);
    rep(i, n){
        cin >> x[i];
    }
    rep(i, m){
        cin >> y[i];
    }

    vector<lint> xsum(n + 1), ysum(m + 1);
    REP(i, 1, n + 1){
        xsum[i] = x[i - 1] + xsum[i - 1];
    }
    REP(i, 1, m + 1){
        ysum[i] = y[i - 1] + ysum[i - 1];
    }

    lint dxsum = 0, dysum = 0;
    REP(i, 1, n){
        dxsum += x[i] * i - xsum[i];
        dxsum %= MOD;
    }
    REP(i, 1, m){
        dysum += y[i] * i - ysum[i];
        dysum %= MOD;
    }

    lint ans = (dxsum * dysum) % MOD;
    cout << ans << endl;

    return 0;
}