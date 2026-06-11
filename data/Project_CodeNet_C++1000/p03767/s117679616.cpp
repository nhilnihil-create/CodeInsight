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
    vector<ll> a(3 * N);
    REP(i, 3 * N)
    {
        cin >> a[i];
    }
    sort(ALL(a));
    ll ans = 0;
    REP(i, N)
    {
        ans += a[3 * N - 1 - 2 * i - 1];
    }

    cout << ans << endl;
}
