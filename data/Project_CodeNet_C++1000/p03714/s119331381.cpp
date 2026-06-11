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
    REP(i, 3 * N) cin >> a[i];

    priority_queue<ll, vector<ll>, greater<ll>> head;
    ll headSum = 0;
    REP(i, N)
    {
        head.push(a[i]);
        headSum += a[i];
    }
    map<ll, ll> headSumMap;
    headSumMap[0] = headSum;
    for (ll k = 1; k <= N; ++k)
    {
        headSum += a[N - 1 + k];
        head.push(a[N - 1 + k]);
        headSum -= head.top();
        head.pop();
        headSumMap[k] = headSum;
    }

    priority_queue<ll> tail;
    ll tailSum = 0;
    REP(i, N)
    {
        tail.push(a[2 * N + i]);
        tailSum += a[2 * N + i];
    }
    map<ll, ll> tailSumMap;
    tailSumMap[N] = tailSum;
    for (ll k = 1; k <= N; ++k)
    {
        tailSum += a[2 * N - k];
        tail.push(a[2 * N - k]);
        tailSum -= tail.top();
        tail.pop();
        tailSumMap[N - k] = tailSum;
    }

    ll ans = LONG_MIN;
    for (ll k = 0; k <= N; ++k)
    {
        ans = max(ans, headSumMap[k] - tailSumMap[k]);
    }
    cout << ans << endl;
}
