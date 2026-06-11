#include <bits/stdc++.h>
using namespace std;

#define REP(i, start, count) for(int i=(start); i<(int)(count); ++i)
#define rep(i, count) REP(i, 0, count)
#define ALLOF(c) (c).begin(), (c).end()

using ll = long long;
using ull = unsigned long long;
using veci = vector<int>;
using vecll = vector<ll>;
using vecull = vector<ull>;

string X;

int main(void) {
    cin >> X;

    stack<char> stk;

    ll ans = X.size();
    for (int i = 0;i < X.size(); ++i) {

        if (stk.size() == 0) {
            stk.push(X[i]);
            continue;
        }

        while (stk.size() >= 2) {
            char t = stk.top(); stk.pop();
            char s = stk.top(); stk.pop();

            if (s == 'S' && t == 'T') {
                ans -= 2;
                continue;
            }

            stk.push(s);
            stk.push(t);
            break;
        }

        if (X[i] == 'T' && stk.top() == 'S') {
            stk.pop();
            ans -= 2;
        }
        else {
            stk.push(X[i]);
        }

    }

    cout << ans << endl;
    return 0;
}
