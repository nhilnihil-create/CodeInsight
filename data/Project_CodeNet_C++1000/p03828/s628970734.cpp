#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<string> vs;
const long long INF = 1LL << 60;
const int INT_INF = 1 << 30;
const double PI = acos(-1.0);
const ll MOD = 1000000007;

unordered_map<ll, ll> counts;

void prime_factorize(ll N){
    for(ll i = 2; i * i <= N; i++){
        if (N % i != 0) continue;
        while (N % i == 0){
            counts[i]++;
            N /= i;
        }
    }
    if (N != 1) counts[N]++;
}

int main() {
    ll N;
    cin >> N;
    rep2(i, 2, N + 1){
        prime_factorize(i);
    }
    ll ans = 1;
    for(auto c: counts){
        ans *= c.second + 1;
        ans %= MOD;
    }
    cout << ans << endl;
}
