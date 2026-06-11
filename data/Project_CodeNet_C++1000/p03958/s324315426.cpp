#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, int>;
using vpii = vector<pair<int, int>>;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep1(i, n) for (int i = 1; i < (int)n; i++)
const ll mod = 1e9 + 7;
const ll inf = 1e12;
const double pi = 3.141592;
const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, 1, 0, -1};

template <class T>
bool contain(const string &s, const T &v)
{
    return s.find(v) != std::string::npos;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int k, t;
    cin >> k >> t;
    vector<int> a(t);
    int sum = 0;
    rep(i, t){ 
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    int sum1 = sum - a[t - 1];
    int sum2 = a[t - 1];
    int ans = abs(sum1-sum2);
    rep(i, t)
    {
        sum1 -= a[i];
        sum2 += a[i];
        ans = min(ans, abs(sum1 - sum2));
    }

    cout << max(0,ans-1) << "\n";
    return 0;
}