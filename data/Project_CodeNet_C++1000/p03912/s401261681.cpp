#include "bits/stdc++.h"
using namespace std;
#define int long long
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, a, b) for(int i=(b-1);i>=(a);i--)
#define REP(i, n) for(int i=0; i<(n); i++)
#define RREP(i, n) for(int i=(n-1); i>=0; i--)
#define REP1(i, n) for(int i=1; i<=(n); i++)
#define RREP1(i, n) for(int i=(n); i>=1; i--)
#define ALL(a) (a).begin(),(a).end()
#define UNIQUE_SORT(l) sort(ALL(l)); l.erase(unique(ALL(l)), l.end());
#define CONTAIN(a, b) find(ALL(a), (b)) != (a).end()
#define out(...) printf(__VA_ARGS__)
#if DEBUG
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...) /* ... */
#endif
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}
void _OUT() {}; template<class H, class... T> void _OUT(H &h, T &... t) { cout<<' '<<h; _OUT(t...); };
template<class H, class... T> void _P(H &h, T &... t) { cout<<h; _OUT(t...); };
#define _PN(...) _P(__VA_ARGS__); cout << endl;

void solve();
signed main()
{
#if DEBUG
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}

/*================================*/
#if DEBUG
#define SIZE 100
#else
#define SIZE 223450
#endif

int N,M;
vector<int> X(SIZE),P(SIZE);
map<int,int> V[SIZE];

void solve() {
    cin>>N>>M;
    REP(i,N) {
        cin>>X[i];
        int m = X[i]%M;
        P[m]++;
        V[m][X[i]]++;
    }
    int ans = 0;
    REP(i,M/2+1) {
        int j = (M-i)%M;
        if (i==j) {
            int cnt = P[i]/2;
            ans += cnt;
            P[i] -= cnt*2;
        } else {
            int cnt = min(P[i],P[j]);
            ans += cnt;
            P[i] -= cnt;
            P[j] -= cnt;
        }
    }
    REP(i,M) {
        for (auto p:V[i]) {
            if (P[i]<2) break;
            if (p.second<2) continue;
            int cnt = min(p.second/2, P[i]/2);
            ans += cnt;
            P[i] -= cnt*2;
        }
    }
    _PN(ans);
}

