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
    int h, w;
    cin >> h >> w;
    vector<int> p(26, 0);
    rep (i, h) {
        string s;
        cin >> s;
        rep (j, w) {
            int x = s[j] - 'a';
            p[x]++;
        }
    }
    int four, two, one;
    four = two = one = 0;
    rep (i, 26) {
        four += p[i] / 4;
        p[i] = p[i] % 4;
        two += p[i] / 2;
        p[i] = p[i] % 2;
        one += p[i];
    }
    int n = h / 2;
    int m = w / 2;
    if (h % 2 == 0 && w % 2 == 0) {
        if (n * m == four) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else if (h % 2 == 0  || w % 2 == 0) {
        if (one == 0 && four >= n * m) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        if (one == 1 && four >= n * m) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}


