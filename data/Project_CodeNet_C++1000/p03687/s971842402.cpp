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

bool is_prime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

vector<int> argsort(vector<int> v) {
    vector<int> indices(v.size());
    iota(indices.begin(), indices.end(), 0);
    // ソートする。
    sort(indices.begin(), indices.end(), [&v](int i1, int i2) {
        return v[i1] < v[i2];
    });
    return indices;
}


int main() {
    string t;
    cin >> t;
    int p = 1e9;
    rep (i, t.size()) {
        if (t[0] != t[i]) {
            break;
        } else if (i == t.size() - 1) {
            cout << 0 << endl;
            exit(0);
        }
    }
    for (int target = 0; target < 26; ++target) {


        int ans = 1;
        bool flag = false;
        string s = t;
        while (true) {
            if (flag || ans > s.size()) {
                break;
            }
            string _s;
            rep (i, s.size() - 1) {
                if (s[i] - 'a' == target || s[i + 1] - 'a' == target) {
                    _s += char('a' + target);
                } else {
                    _s += s[i];
                }
            }
            rep (i, _s.size()) {
                if (_s[i] != _s[0]) {
                    break;
                } else if (i == _s.size() - 1) {
                    chmin(p, ans);
                    flag = 1;
                    break;
                }
            }
            s = _s;
            ans++;
        }

    }
    cout << p << endl;
}