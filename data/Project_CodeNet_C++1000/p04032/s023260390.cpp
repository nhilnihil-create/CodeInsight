#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <numeric>
#include <functional>
#include <cmath>
#include <cassert>
#include <string>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, ll> PL;
const ll mod = 1000000007;
const ll MOD = 1000000007;
const ll INF = 1LL << 60;
#define PI (acos(-1))

ll lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}
vector<ll> divisor(ll n)
{
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ret.push_back(i);
            if (i * i != n)
                ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}

const ll MAX = 510000;
// const ll MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(ll n, ll k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll a[101];
ll solve()
{
    string s;
    cin >> s;
    map<char, ll> m;
    m[s[0]]++;
    m[s[1]]++;
    if(s.length() == 2){
        if(m[s[0]] == 2){
            cout << 1 << " " << 2 << endl;
            return 0;
        }
    }

    for(int i=2; i < s.length(); i++){
        m[s[i]]++;
        if(m[s[i]] >= 2){
            cout << i - 1 << " " << i + 1 << endl;
            return 0;
        }else if(m[s[i - 1]] >=2){
            cout << i - 1 << " " << i + 1 << endl;
            return 0;
        }
        m[s[i - 2]]--;
    }
    cout << -1 << " " << -1 << endl;

    return 0;
}

int main()
{
    //cout.precision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
