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
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, f, n) for (int i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;

void print_stack(stack<char> st) {
    if (st.empty()) return;

    auto x = st.top();
    st.pop();

    print_stack(st);

    cout << x;
    st.push(x);
}

int main() {
    string s;
    cin >> s;

    stack<char> a;
    rep(i, s.length()) {
        if (s[i] == '0')
            a.push('0');
        else if (s[i] == '1')
            a.push('1');
        else if (s[i] == 'B') {
            if (!(a.empty())) {
                a.pop();
            }
        }
    }

    print_stack(a);
    cout << endl;
    return 0;
}
