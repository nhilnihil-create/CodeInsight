#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()

const ll INF = 1000000000000000000;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n+1, 0);
    rep (i, m) {
        int k;
        cin >> k;
        p[k]++;
        cin >> k;
        p[k]++;
    }
    rep (i, n+1) {
        if (p[i] % 2) {
            cout << "NO" << endl;
            exit(0);
        }
    }
    cout << "YES" << endl;
}