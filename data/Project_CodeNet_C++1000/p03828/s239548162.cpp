#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

vector<pair<int, int>> factorization(int num) // 数値を受け取り素因数分解の結果を返す
{
    map<int, int> mp;
    int n = 2;
    while (num != 1)
    {
        if (num % n == 0)
        {
            mp[n]++;
            num /= n;
            continue;
        }
        n++;
    }
    vector<pair<int, int>> ret;
    for (auto m : mp)
    {
        ret.push_back(make_pair(m.first, m.second));
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        auto facs = factorization(i);
        for (auto fac : facs)
        {
            mp[fac.first] += fac.second;
        }
    }
    ll ans = 1;
    vector<int> tmp;
    for (auto m : mp)
    {
        tmp.push_back(m.second);
    }
    reverse(tmp.begin(), tmp.end());
    for (int t : tmp)
    {
        ans = (ans * (t + 1)) % MOD;
    }
    cout << ans << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}
