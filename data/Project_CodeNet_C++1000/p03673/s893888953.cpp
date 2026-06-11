#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    deque<string> dq;
    rep(i, n) {
        string a;
        cin >> a;
        if (i % 2 == 0) dq.push_back(a);
        else dq.push_front(a);
    }
    if (n % 2 == 1) reverse(ALL(dq));
    rep(i, n) {
        string s = dq.front();
        cout << s << " ";
        dq.pop_front();
    }
    cout << endl;
    return 0;
}