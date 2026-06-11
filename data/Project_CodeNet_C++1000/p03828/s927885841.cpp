#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);
//----------------------------------------------------------------

vector<pair<long long, long long> > prime_factorize(long long n) {
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

int main(){
    int N;
    cin >> N;
    map<ll,ll> S;

    rep(i,N) {
        auto F = prime_factorize(i+1);

        rep(j,F.size()) {
            if(!S.count(F[j].first)) {
                S[F[j].first]=F[j].second;
            }
            else {
                S[F[j].first] += F[j].second;
            }
        }

    }

    ll ans = 1;
    for (auto p:S) {
        ans *= p.second+1;
        ans %= MOD;
    }
    cout << ans << endl;
}
