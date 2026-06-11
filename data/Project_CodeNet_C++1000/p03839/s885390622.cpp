#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const ll inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

int N, K, s;
ll sum, ans;

#include <bits/stdc++.h>
using namespace std;

string to_string(string s)
{
    return '"' + s + '"';
}

string to_string(const char *s)
{
    return to_string((string)s);
}

string to_string(bool b)
{
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p)
{
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v)
{
    bool first = true;
    string res = "{";
    for (const auto &x : v)
    {
        if (!first)
        {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << " " << to_string(H);
    debug_out(T...);
}

int main()
{
    cin >> N >> K;
    vector<ll> a(N);
    vector<ll> Sa(N + 1), S(N + 1);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        Sa[i + 1] = Sa[i] + a[i];
        S[i + 1] += S[i] + max(0LL, a[i]);
    }

    for (int i = K; i <= N; i++)
    {
        ll b = Sa[i] - Sa[i - K] + (S[N] - S[i]) + S[i - K];
        ll w = (S[N] - S[i]) + S[i - K];
        ans = max(max(b, w), ans);
    }

    cout << ans << endl;
}