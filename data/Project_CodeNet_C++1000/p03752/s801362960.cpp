#include <bits/stdc++.h>
#include <climits>
using namespace std;
// rep macro
#define rep(i, n)        for (int i = 0; i < (int)(n); i++)
#define rev(i, n)        for (int i = (int)(n - 1); i >= 0; i--)
#define rep2(i, s, n)    for (int i = (s); i < (int)(n); i++)
#define rev2(i, s, n)    for (int i = (int)(n) - 1; i >= (int)(s); i--)
#define bitrep(i, n)     for (int i = 0; i < (1 << (int)(n)); i++)
#define bitrep2(i, s, n) for (int i = (s); i < (1 << (int)(n)); i++)
// vector macro
#define all(v) v.begin(), v.end()
using vi  = vector<int>;
using vvi = vector<vector<int>>;
using vl  = vector<long>;
using vvl = vector<vector<long>>;
using vb  = vector<bool>;
using vvb = vector<vector<bool>>;
// math macro
#define lcm(a, b) a / __gcd(a, b) * b
// print macro
#define println(x) cout << x << endl
#define Yes println("Yes")
#define No println("No")
#define YES println("YES")
#define NO println("NO")
// pair macro
#define x first
#define y second
using pii = pair<int, int>;
using pdd = pair<double, double>;
// memo
// desc sort: sort(vec.begin(), vec.end(), greater<int>());

int main()
{
    int n, k; cin >> n >> k;
    vi a(n); rep(i, n) cin >> a[i];
    long long min_cost = LLONG_MAX;
    bitrep(b, n)
    {
        bitset<14> bs(b);
        vi ta = a;
        long long cost = 0;
        int w = 0;
        rep2(i, 1, n)
        {
            if (ta[i] > ta[w]) w = i;
            else if (bs[i-1] == 1)
            {
                cost += ta[w] - ta[i] + 1;
                ta[i] = ta[w] + 1;
                w = i;
            }
        }
        int cnt = 1; int v = 0;
        rep2(i, 1, n)
        {
            if (ta[i] > ta[v])
            {
                cnt++;
                v = i;
            }
        }
        if (cnt >= k)
        {
            min_cost = min(cost, min_cost);
        }
    }
    cout << min_cost << endl;
}