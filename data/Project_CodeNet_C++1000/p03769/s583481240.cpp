#include <bits/stdc++.h>

using namespace std;

using ll = long long;

deque<int> l, r;

int nxt = 1;

void go(ll x) {
    if (x == 1) {
        return;
    } else if (x % 2 == 1) {
        go(x - 1);
        l.push_back(nxt);
        r.push_front(nxt);
        nxt++;
    } else {
        go(x / 2);
        l.push_back(nxt);
        r.push_back(nxt);
        nxt++;
    }
}

int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin);
#endif
    ll n;
    cin >> n;

    go(n);
    l.push_back(nxt);
    r.push_front(nxt);
    nxt++;

    cout << l.size() + r.size() << "\n";
    for (int x : l) {
        cout << x << " ";
    }
    for (int x : r) {
        cout << x << " ";
    }
    cout << "\n";

}
