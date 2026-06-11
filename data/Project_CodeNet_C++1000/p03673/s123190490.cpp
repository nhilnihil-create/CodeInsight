#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n; cin >> n;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (i % 2 == 0) dq.emplace_front(a);
        else dq.emplace_back(a);        
    }

    if (n % 2 != 0) {
        for (int i = 0; i < n; i++) {
            cout << dq.front() << " ";
            dq.pop_front();
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            cout << dq.back() << " ";
            dq.pop_back();
        }
    }

    cout << endl;
    return 0;
}