#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#pragma region Macros
#define FOR(i, m, n) for (ll i = (ll)(m); i < (ll)(n); i++)
#define rep(i, n) FOR(i, 0, n)

template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

template <class T> string join(const T &v, const string delim = ",")
{
    if (v.empty())
        return "";

    ostringstream res;
    res << v[0];
    for (int i = 1; i < v.size(); i++)
    {
        res << delim << v[i];
    }
    return res.str();
}

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << ":" << #x << " = " << (x) << endl;
#else
#define dbg
#endif

#pragma endregion Macros

int main()
{
    int N;
    cin >> N;

    vector<vector<tuple<int, ll>>> g(N, vector<tuple<int,ll>>());

    rep(i,N-1){
        int a,b;
        ll c;
        cin >> a >> b;
        a--;
        b--;
        cin >> c;

        g[a].push_back(make_tuple(b, c));
        g[b].push_back(make_tuple(a, c));
    }

    int Q, K;
    cin >> Q >> K;
    K--;

    ll INF = 100100100100100100LL;

    vector<ll> cost(N,INF);
    cost[K] = 0;

    queue<int> q;
    q.push(K);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for (auto t : g[cur]) {
            int n = get<0>(t);
            int c = get<1>(t);

            if(cost[n] != INF) continue;

            q.push(n);
            cost[n] = cost[cur] + c;
        }
    }


    rep(q,Q){
        int x,y;
        cin >> x >> y;
        x--;
        y--;

        cout << cost[x] + cost[y] << endl;
    }
}
