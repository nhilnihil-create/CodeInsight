#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ull unsigned long long
#define pw(x) (1LL << (x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"

using namespace std;

const int MOD = 1000000007;

void diviser(long n, unordered_map<long, long> &mp)
{
    for (long i = 2; i * i <= n; ++i)
    {
        while (n % i == 0)
            n /= i, ++mp[i];
        mp[i] %= MOD;
    }
    if (n != 1)
        ++mp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long N;
    cin >> N;

    unordered_map<long, long> mp;

    for (long i = 2; i <= N; ++i)
        diviser(i, mp);

    long ans = 1;
    for (auto p : mp)
        ans *= (1 + p.second), ans %= MOD;

    cout << ans << '\n';

    return 0;
}