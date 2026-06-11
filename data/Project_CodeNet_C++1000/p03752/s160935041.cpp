#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Edge = pair<int, int>;
using Graph = vector<vector<Edge>>;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
const ll MOD = 1000000007;
const ll nmax = 8;
const ll INF = 1e11;

class UnionFind
{
public:
    vector<ll> Parent;

    UnionFind(ll N)
    {
        Parent = vector<ll>(N, -1);
    }
    ll find(ll A)
    {
        if (Parent[A] < 0)
            return A;
        return Parent[A] = find(Parent[A]);
    }

    ll size(ll A)
    {
        return -Parent[find(A)];
    }

    bool Union(ll A, ll B)
    {
        A = find(A);
        B = find(B);
        if (A == B)
        {
            return false;
        }
        if (size(A) < size(B))
            swap(A, B);

        Parent[A] += Parent[B];
        Parent[B] = A;

        return true;
    }
};

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    ll g = gcd(a, b);
    return a / g * b;
}

ll mulMod(ll a, ll b)
{
    return (((a % MOD) * (b % MOD)) % MOD);
}

ll powMod(ll a, ll p)
{
    if (p == 0)
    {
        return 1;
    }
    else if (p % 2 == 0)
    {
        ll half = powMod(a, p / 2);
        return mulMod(half, half);
    }
    else
    {
        return mulMod(powMod(a, p - 1), a);
    }
}

ll ceil(ll a, ll b)
{
    return (a + b - 1) / b;
}

bool isOK(map<char, ll> cnter, ll cnt, ll K, char c)
{
    if (cnt == K)
    {
        if (cnter[c] >= 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (cnt == K - 1)
    {
        if (cnter[c] == 0)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    ll ans = INF;
    for (int bit = 0; bit < (1 << N); bit++)
    {
        ll prev = -1;
        ll cost = 0;
        vector<ll> copy(N);
        copy = a;
        for (int i = 0; i < N; i++)
        {
            if (bit & (1 << i))
            {
                // i番目の建物を増築する
                if (copy[i] <= prev)
                {
                    cost += prev + 1 - copy[i];
                    copy[i] = prev + 1;
                    prev = copy[i];
                }
                else
                {
                    prev = copy[i];
                }
            }
            else
            {
                prev = max(prev, copy[i]);
            }
        }

        prev = -1;
        ll cnt = 0;
        for (int i = 0; i < N; i++)
        {
            if (prev < copy[i])
            {
                cnt++;
                prev = copy[i];
            }
        }
        if (K <= cnt)
        {
            ans = min(ans, cost);
        }
    }

    cout << ans << endl;

    return 0;
}
