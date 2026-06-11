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
    string s;
    int k;
    cin >> s >> k;
    rep (i, s.size()) {
        if (s[i] == 'a') continue;
        int toa = 'z' + 1 - s[i];
        if (toa <= k) {
            k -= toa;
            s[i] = 'a';
        }
    }
    if (k > 0) {
        k %= 26;
        s[s.size() - 1] = (s[s.size() - 1] - 'a' + k) % 26 + 'a';
    }
    cout << s << endl;
}