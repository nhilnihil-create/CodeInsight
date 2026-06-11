#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    vector<ll> indexA(N + 1);
    REP(i, N)
    {
        ll a;
        cin >> a;
        indexA[a] = i;
    }

    ll ans = 0;
    set<ll> s;
    for (ll i = 1; i <= N; ++i)
    {
        ll l, r;
        s.insert(indexA[i]);
        auto it = s.find(indexA[i]);
        if (it != s.begin())
        {
            it--;
            l = *(it);
            l++;
        }
        else
        {
            l = 0;
        }
        it = s.find(indexA[i]);
        it++;
        if (it != s.end())
        {
            r = *it;
            r--;
        }
        else
        {
            r = N - 1;
        }
        ans += i * (indexA[i] - l + 1) * (r - indexA[i] + 1);
    }

    cout << ans << endl;
}
