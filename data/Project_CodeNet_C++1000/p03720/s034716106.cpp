#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(2 * m);
    for (int i = 0; i < 2 * m; i++) {
        cin >> a[i];
    }
    
    for (int j = 1; j <= n; j++) {
        int count = 0;
        for (int i = 0; i < 2 * m; i++) {
            if (a[i] == j) count++;
        }
        cout << count << endl;
    }
}