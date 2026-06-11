#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MIN(a) *min_element(all(a))
#define MAX(a) *max_element(all(a))
#define SUM(a) accumulate(all(a), 0LL)
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define RREP(i, n) for(int (i)=(n)-1; (i)>=0; (i)--)
#define FOR(i, m, n) for(int (i)=(m); (i)<(n); i++)
#define FORR(i, m, n) for(int (i)=(n)-1; (i)>=(m); i--)
#define debug(x) cerr << #x << " = " << x << endl
//#define int long long

typedef long long ll;
//ll const MOD = 998244353;
ll const MOD = 1e9+7;
int const inf = 1e9;
ll const INF = 1e18;

inline void ios_(){cin.tie(0); ios::sync_with_stdio(false);}
template<typename T> int size(const T& a){return (int)a.size();}
template<typename T> T Div(T a, T b){return (a + b - 1) / b;}
template<typename T> bool chmin(T& a, const T& b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, const T& b){if(a < b){a = b; return true;} return false;}



signed main(){
    int n, m;
    cin >> n >> m;

    vector<int> v(1e5+10);

    REP(i, n){
        int a;
        cin >> a;
        v[a]++;
    }

    auto fn = [](const pair<int,int>& a, const pair<int,int>& b){return a.second%2 < b.second%2;};

    vector<
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            decltype(fn)
        >
    >
    que(
        m,
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            decltype(fn)
        >(fn)
    );
    
    REP(i, v.size()){
        if(v[i] == 0) continue;
        que[i%m].push(make_pair(i, v[i]));
    }

    int ans = 0;

    REP(i, m){
        int a = i, b = (m - i) % m;
        if(a == b){
            int cnt = 0;
            while(!que[a].empty()){
                cnt += que[a].top().second;
                que[a].pop();
            }
            ans += cnt / 2;
            continue;
        }
        while(!que[a].empty() && !que[b].empty()){
            auto p = que[a].top();
            que[a].pop();
            auto q = que[b].top();
            que[b].pop();
            p.second--;
            q.second--;
            ans++;
            if(p.second > 0) que[a].push(p);
            if(q.second > 0) que[b].push(q);
        }
        while(!que[a].empty()){
            ans += que[a].top().second / 2;
            que[a].pop();
        }
        while(!que[b].empty()){
            ans += que[b].top().second / 2;
            que[b].pop();
        }
    }

    cout << ans << endl;

    return 0;
}
