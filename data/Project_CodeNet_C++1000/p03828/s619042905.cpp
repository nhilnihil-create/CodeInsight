#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;

//因数分解→map<素因数,それぞれいくつか>の形に格納
map<ll, ll> prime; //素因数分解でそれぞれの素数がいくつ出てきたかを保存するmap

//O(√n)
//整列済み(mapはkeyで自動で整列される)
void prime_factorize(ll n)
{
    if (n <= 1)
        return;
    ll l = sqrt(n);
    for (ll i = 2; i <= l; i++)
    {
        if (n % i == 0)
        {
            prime_factorize(i);
            prime_factorize(ll(n / i));
            return;
        }
    }
    //mapでは存在しないkeyの場合も自動で構築される
    prime[n]++;
    return;
}

int main()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        prime_factorize(i);
    }

    ll ans = 1;
    for (auto p : prime)
    {
        ans = (ans * (p.second + 1)) % MOD;
    }

    cout << ans << endl;
}