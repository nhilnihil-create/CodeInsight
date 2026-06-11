#include<iostream>
using namespace std;

int main() {
    int n, m, s, t;
    cin >> n >> m;
    bool w1[n+10]{}, wn[n+10]{};

    for (int i = 0; i < m; i++) {
        cin >> s >> t;
        if (s == 1) w1[t] = true;
        if (t == n) wn[s] = true;
    }

    for (int i = 2; i < n; i++) {
        if (w1[i] & wn[i]) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    
    cout << "IMPOSSIBLE" << endl;
}