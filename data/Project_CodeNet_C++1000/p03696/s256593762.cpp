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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ctr = 0;
    int pena = 0;
    rep (i, n) {
        if (s[i] == ')') {
            if (ctr > 0) {
                ctr--;
            } else {
                pena++;
            }
        } else {
            ctr++;
        }
    }
    ctr = 0;
    int penb = 0;
    for (int i = n - 1; i >= 0; --i){
        if (s[i] == '(') {
            if (ctr > 0) {
                ctr--;
            } else {
                penb++;
            }
        } else {
            ctr++;
        }
    }
    string t = "";
    rep (i, pena) {
        t += '(';
    }
    s = t + s;
    t = "";
    rep (i, penb) {
        t += ')';
    }
    s = s + t;
    cout << s << endl;
}