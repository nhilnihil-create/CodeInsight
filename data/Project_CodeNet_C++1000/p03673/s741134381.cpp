#include <bits/stdc++.h>

#include <deque>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    deque<int> a;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    deque<int> b;
    for (int i = 0; i < n; i++) {
        if ((n - i) % 2 == 1) {
            b.push_back(a.front());
            a.pop_front();
        } else {
            b.push_front(a.front());
            a.pop_front();
        }
    }

    while (!b.empty()) {
        cout << b.back() << " ";
        b.pop_back();
    }

    return 0;
}
