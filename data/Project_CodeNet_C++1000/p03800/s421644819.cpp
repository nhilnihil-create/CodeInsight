#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Edge = int;
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

vector<ll> tsort(Graph G)
{
    ll N = G.size();
    vector<ll> in(N);
    for (auto &&edges : G)
    {
        for (auto &&edge : edges)
        {
            in[edge]++;
        }
    }

    queue<int> que;

    for (int i = 0; i < N; i++)
    {
        if (in[i] == 0)
        {
            que.push(i);
        }
    }
    int cnt = 0;
    vector<ll> ans;
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        ans.push_back(v);
        for (auto &&next : G[v])
        {

            in[next]--;
            if (in[next] == 0)
            {
                que.push(next);
            }
        }
    }
    return ans;
}
vector<bool> check(string s, vector<bool> S)
{
    for (int i = 2; i < S.size(); i++)
    {
        if (S[i - 1])
        {
            if (s[i - 1] == 'o')
            {
                S[i] = S[i - 2];
            }
            else
            {
                S[i] = !S[i - 2];
            }
        }
        else
        {
            if (s[i - 1] == 'o')
            {
                S[i] = !S[i - 2];
            }
            else
            {
                S[i] = S[i - 2];
            }
        }
    }
    return S;
}

bool correct(string s, vector<bool> S, ll N)
{
    bool ret = true;
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            if (S[0])
            {
                if ((s[0] == 'o' && S[1] == S[N - 1]) || (s[0] == 'x' && S[1] != S[N - 1]))
                {
                }
                else
                {
                    ret = false;
                }
            }
            else
            {
                if ((s[0] == 'o' && S[1] != S[N - 1]) || (s[0] == 'x' && S[1] == S[N - 1]))
                {
                }
                else
                {
                    ret = false;
                }
            }
        }
        else if (i == N - 1)
        {
            if (S[N - 1])
            {
                if ((s[N - 1] == 'o' && S[0] == S[N - 2]) || (s[N - 1] == 'x' && S[0] != S[N - 2]))
                {
                }
                else
                {
                    ret = false;
                }
            }
            else
            {
                if ((s[N - 1] == 'o' && S[0] != S[N - 2]) || (s[N - 1] == 'x' && S[0] == S[N - 2]))
                {
                }
                else
                {
                    ret = false;
                }
            }
        }
        else
        {
            if (S[i])
            {
                if ((s[i] == 'o' && S[i + 1] == S[i - 1]) || (s[i] == 'x' && S[i + 1] != S[i - 1]))
                {
                }
                else
                {
                    ret = false;
                }
            }
            else
            {
                if ((s[i] == 'x' && S[i + 1] == S[i - 1]) || (s[i] == 'o' && S[i + 1] != S[i - 1]))
                {
                }
                else
                {
                    ret = false;
                }
            }
        }
    }
    return ret;
}
vector<bool> solve(long long N, std::string s)
{
    vector<bool> S(N, false);
    S[0] = true;
    S[1] = true;
    S = check(s, S);

    if (correct(s, S, N))
    {
        return S;
    }
    S[0] = true;
    S[1] = false;
    S = check(s, S);
    if (correct(s, S, N))
    {
        return S;
    }

    S[0] = false;
    S[1] = true;
    S = check(s, S);
    if (correct(s, S, N))
    {
        return S;
    }

    S[0] = false;
    S[1] = false;
    S = check(s, S);
    if (correct(s, S, N))
    {
        return S;
    }
    vector<bool> emtpy;
    return emtpy;
}

int main()
{
    long long N;
    scanf("%lld", &N);
    std::string s;
    std::cin >> s;
    vector<bool> ans;

    ans = solve(N, s);
    if (ans.size() == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            if (ans[i])
            {
                cout << "S";
            }
            else
            {
                cout << "W";
            }
        }
        cout << endl;
    }
    return 0;
}
