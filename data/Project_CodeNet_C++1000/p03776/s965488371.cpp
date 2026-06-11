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
#define SIZE 55
#else
#define SIZE 55
#endif

int N,A,B;
vector<int> V;

int _com[55][55];

int COM(int n, int k) {
    if (n==0 || k==0 || n==k) return 1;
    if (_com[n][k]) return _com[n][k];
    return _com[n][k] = COM(n-1,k) + COM(n-1,k-1);
}

void solve() {
    cin>>N>>A>>B;
    V.resize(N);
    REP(i,N) {
        cin>>V[i];
    }
    sort(ALL(V));
    reverse(ALL(V));
    double sum = accumulate(V.begin(), V.begin()+A, (double)0);
    double ave = sum/A;
    int v = V[A-1];
    int mii = find(ALL(V),v)-V.begin();
    int num = count(ALL(V),v);
    int ans = 0;
    if (V[0]==v) {
        FOR(c,A,min(B,num)+1) {
            ans += COM(num,c);
        }
    } else {
        ans = COM(num,A-mii);
    }
    printf("%.10f\n%lld\n",ave,ans);
}

