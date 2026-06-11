#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, t, ans = 0;
    cin >> k >> t;
    int a;
    priority_queue<int> pq;
    for(int i = 0; i < t; ++i) {
        cin >> a;
        pq.push(a);
    }
    pq.push(0);
    while(pq.size() != 1) {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        x -= y;
        pq.push(x);
    }
    cout << max(pq.top() - 1, 0) << '\n';

    return 0;
}
