#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, x, n) for (int i = x; i < (n); i++)
#define all(n) begin(n), end(n)
struct cww
{
    cww()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
} star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<char> vchar;
typedef vector<vector<int>> vvint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef unsigned long long ull;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts)
{
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }

template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v)
{
    for (auto &e : t)
        fill_v(e, v);
}
int main()
{
    int N;
    string S;

    cin >> N;
    cin >> S;
    deque<char> ans(N);
    int m = 0; // ')' の数-'('の数
    int b = 0;
    for (size_t i = 0; i < N; i++)
    {
        ans[i] = S[i];
    }

    for (int i = 0; i < N; ++i)
    {
        if (S[i] == ')')
            m++;
        else
            m--;

        if (m > 0)
        {
            ans.push_front('(');
            m--;
        }
    }
    m = 0;
    for (int i = N - 1; i >= 0; --i)
    {
        if (S[i] == '(')
            m++;
        else
            m--;

        if (m > 0)
        {
            ans.push_back(')');
            m--;
        }
    }
    for (auto &&i : ans)
    {
        cout << i;
    }

    return 0;
}