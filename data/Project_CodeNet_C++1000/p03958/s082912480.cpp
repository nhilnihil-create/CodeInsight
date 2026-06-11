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

int main() {
    int k, t;
    cin >> k >> t;
    vector<int> a(t);
    rep(i, t) {
        cin >> a[i];
    }
    sort(all(a), greater<int>());
    if (a[0] <= k / 2) {
        cout << 0 << endl;
    } else {
        cout << k - ((k - a[0]) * 2 + 1) << endl;
    }
}
