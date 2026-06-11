#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); ++i)

struct item
{
    ll w, v;
};
ll n, W;
vector<item> items;
map<pair<int, int>, int> dic;

ll rec_dp(ll i, ll w)
{
    if (dic.count(make_pair(i, w)) > 0)
    {
        return dic[make_pair(i, w)];
    }
    ll result;
    if (i == n)
    {
        result = 0;
    }
    else if (w - items[i].w < 0)
    {
        result = rec_dp(i + 1, w);
    }
    else
    {
        result = max(
            rec_dp(i + 1, w),
            rec_dp(i + 1, w - items[i].w) + items[i].v);
    }
    dic[make_pair(i, w)] = result;
    return result;
}

int main()
{
    cin >> n >> W;
    items.resize(n);
    rep(i, n)
    {
        cin >> items[i].w >> items[i].v;
    }
    cout << rec_dp(0, W) << endl;
}
