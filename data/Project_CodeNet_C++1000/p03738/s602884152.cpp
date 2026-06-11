#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
typedef long long ll;
typedef long double ld;
const long long INF = 1e18;
# define len(x) ((int)(x).size())
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define foreps(i, m, n) for(int i = m;i < n;i++)
# define ALL(x) (x).begin(), (x).end()
# define rall(x) (x).rbegin(), (x).rend()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int firstPlace(string a, string b) { 
    int A = a.at(0), B = b.at(0);
    if (A < B) return true;
    else return false;
}

int main() {
    string a, b; cin >> a >> b;

    if (len(b) < len(a)) {
        cout << "GREATER" << endl;
        return 0;
    }
    else if (len(a) < len(b)) {
        cout << "LESS" << endl;
        return 0;
    }
    else if (a == b) { 
        cout << "EQUAL" << endl;
        return 0;
    }
    else if (len(a) == len(b)) {
        if (firstPlace(a, b)) {
            cout << "LESS" << endl;
            return 0;
        }
        else if (!firstPlace(a, b)) {
            cout << "GREATER" << endl;
            return 0;
        }
    }
}