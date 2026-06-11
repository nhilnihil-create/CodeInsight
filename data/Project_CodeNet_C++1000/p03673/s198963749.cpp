/**
 *    author:  FromDihPout
 *    created: 2020-07-31
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    deque<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if ((i % 2) ^ (n % 2)) {
            a.push_front(x);
        }
        else {
            a.push_back(x);
        }
    }
    
    while (!a.empty()) {
        cout << a.front() << ' ';
        a.pop_front();
    }
    cout << '\n';
    
    
    return 0;
}