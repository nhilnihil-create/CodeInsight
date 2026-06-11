#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> a(M), b(M), c(M);
    REP(i, M)
    {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
        c[i] = -c[i];
    }

    vector<ll> dist(N);
    const ll INF = 1ll << 50;
    dist[0] = 0;
    REP(i, N - 1) dist[i + 1] = INF;
    REP(i, N - 1)
    {
        REP(j, M)
        {
            if (dist[a[j]] == INF) continue;
            dist[b[j]] = min(dist[b[j]], dist[a[j]] + c[j]);
        }
    }
    ll ans = -dist[N - 1];

    vector<bool> update(N, false);
    REP(i, N)
    {
        REP(j, M)
        {
            if (dist[a[j]] == INF) continue;
            if (dist[b[j]] > dist[a[j]] + c[j])
            {
                dist[b[j]] = dist[a[j]] + c[j];
                update[b[j]] = true;
            }
            if (update[a[j]]) update[b[j]] = true;
        }
    }
    
    if (update[N - 1])
    {
        cout << "inf" << endl;
    }
    else
    {
        cout << ans << endl;
    }
    
}
