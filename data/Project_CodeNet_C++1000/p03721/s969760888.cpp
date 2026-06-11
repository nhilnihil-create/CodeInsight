#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<pair<int, int>> ab(n);
    rep(i, n)
    {
        cin >> ab[i].first >> ab[i].second;
    }
    map<int, ll> mp;
    rep(i, n)
    {
        mp[ab[i].first] += ab[i].second;
    }
    ll cnt = 0;
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
    {
        cnt += itr->second;
        if (cnt >= k)
        {
            cout << itr->first << endl;
            return 0;
        }
    }
    return 0;
}
