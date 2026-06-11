#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (s.find(x) != s.end()) {
            s.erase(x);
        } else {
            s.insert(x);
        }
    }
    cout << s.size();
}