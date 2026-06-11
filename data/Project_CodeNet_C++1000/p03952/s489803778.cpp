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
const ll INF = 1e9;
bool graph[nmax][nmax];
vector<vector<ll>> dist = vector<vector<ll>>(nmax, vector<ll>(nmax, INF));
void warshall_floyd(ll n)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            for (size_t k = 0; k < n; k++)
            {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
}

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

const string YES = "Yes";
const string NO = "No";

void solve(long long N, long long x)
{
    if (N == 2)
    {
        if (x == 2)
        {
            cout << YES << endl;
            cout << "1 2 3" << endl;
            return;
        }
        else
        {
            cout << NO << endl;
            return;
        }
    }
    if (x == 1 || x == 2 * N - 1)
    {
        cout << NO << endl;
        return;
    }
    else
    {
        cout << YES << endl;
        list<ll> ans;
        ans.push_back(x);
        ans.push_front(x - 1);
        ans.push_back(x + 1);
        if (x - 2 < 1)
        {
            ans.push_front(x + 2);
            int cnt = 0;
            for (int i = 1; i <= 2 * N - 1; i++)
            {
                if (x - 1 <= i && i <= x + 2)
                {
                    continue;
                }
                if (cnt % 2 == 0)
                {
                    ans.push_back(i);
                    cnt++;
                }
                else
                {
                    ans.push_front(i);
                    cnt++;
                }
            }
        }
        else
        {
            ans.push_back(x - 2);
            int cnt = 0;
            for (int i = 1; i <= 2 * N - 1; i++)
            {
                if (x - 2 <= i && i <= x + 1)
                {
                    continue;
                }
                if (cnt % 2 == 0)
                {
                    ans.push_front(i);
                    cnt++;
                }
                else
                {
                    ans.push_back(i);
                    cnt++;
                }
            }
        }

        for (auto &&i : ans)
        {
            cout << i << endl;
        }
    }
}

int main()
{
    long long N;
    scanf("%lld", &N);
    long long x;
    scanf("%lld", &x);
    solve(N, x);
    return 0;
}
