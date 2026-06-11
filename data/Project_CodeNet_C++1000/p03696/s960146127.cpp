#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define INIT    \
    cin.tie(0); \
    ios::sync_with_stdio(false);

template <class T>
inline bool chmax(T& a, T b) {
    return a = (a < b) ? b : a;
}
template <class T>
inline bool chmin(T& a, T b) {
    return a = (a > b) ? b : a;
}

ll const INF = 1LL << 60;
ll const MOD = 1000000007;

void print_stack(stack<char> st) {
    if (st.empty()) return;

    auto x = st.top();
    st.pop();

    print_stack(st);

    cout << x;
    st.push(x);
}

int main() {
    INIT;

    ll N;
    cin >> N;
    string s;
    cin >> s;

    stack<char> a;

    rep(i, N) {
        if (s[i] == '(')
            a.push('(');
        else if (s[i] == ')') {
            if (!(a.empty())) {
                char c = a.top();
                if (c == '(') {
                    a.pop();
                } else {
                    a.push(')');
                }
            } else {
                a.push(')');
            }
        }

        // stack<char> b = a;
        // print_stack(b);
        // cout << endl;
    }

    while (!a.empty()) {
        char c = a.top();
        a.pop();
        if (c == '(') {
            s = s + ")";
        } else if (c == ')') {
            s = "(" + s;
        }
    }

    cout << s << endl;

    return 0;
}