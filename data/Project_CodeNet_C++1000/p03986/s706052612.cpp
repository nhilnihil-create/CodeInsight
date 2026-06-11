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
    cin >> s;
    stack<char> stk;
    rep (i, s.size()) {
        switch (s[i]) {
            case 'S':
                stk.push('S');
                break;
            case 'T':
                if (stk.empty() || stk.top() == 'T') {
                    stk.push('T');
                } else {
                    stk.pop();
                }
        }
    }
    cout << stk.size() << endl;
}