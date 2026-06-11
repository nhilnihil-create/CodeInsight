#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    cin >> n;
    deque<int> dq;
    for(int i = 0; i < n; ++i) {
        cin >> a;
        if(i&1) dq.push_front(a);
        else dq.push_back(a);
    }

    if(n&1) reverse(dq.begin(), dq.end());
    for_each(dq.begin(), dq.end(), [](int x) {
        cout << x << ' ';
    });
    cout << '\n';

    return 0;
}
