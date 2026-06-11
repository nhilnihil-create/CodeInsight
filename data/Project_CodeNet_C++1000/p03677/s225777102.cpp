#include<bits/stdc++.h>
using namespace std;

#define lint long long
#define P pair<int, int>
#define LLP pair<long long, long long>
#define REP(i, x, n) for(int i = (x), i##_len = int(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = int(n) ; i < i##_len ; ++i)
#define reps(i, n) for(int i = 1, i##_len = int(n) ; i <= i##_len ; ++i)
#define rrep(i, n) for(int i = int(n) - 1 ; i >= 0 ; --i)
#define rreps(i, n) for(int i = int(n) ; i > 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())
#define SORT_INV(x) sort((x).rbegin(), (x).rend())

const int IINF = (1 << 30) - 1;
const long long LLINF = 1LL << 61;
const long long MOD = 1000000007LL;
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
const double EPS = 1e-8;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    lint n, m;
    cin >> n >> m;

    vector<lint> a(n);
    rep(i, n){
        cin >> a[i];
        --a[i];
    }

    vector<lint> imos(m + 1);
    vector< vector<lint> > v(m);
    rep(i, n - 1){
        if(a[i] <= a[i + 1]){
            ++imos[a[i] + 1];
            --imos[a[i + 1]];
        }else{
            ++imos[a[i] + 1];
            --imos[m];
            ++imos[0];
            --imos[a[i + 1]];
        }
        v[a[i + 1]].push_back(i);
    }

    reps(i, m){
        imos[i] += imos[i - 1];
    }

    lint now = 0;
    rep(i, n - 1){
        now += min((a[i + 1] - a[i] + m) % m, a[i + 1] + 1LL);
    }

    lint ans = now;
    REP(x, 1, m){
        for(auto i : v[x - 1]){
            now += (a[i + 1] - a[i] + m) % m - 1LL;
        }
        now -= imos[x - 1];
        ans = min(ans, now);
    }

    cout << ans << endl;

    return 0;
}