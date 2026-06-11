#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int t[n];
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    int m;
    cin >> m;
    int p[m], x[m];
    for (int i = 0; i < m; i++) {
        cin >> p[i] >> x[i];
    }
    for (int d = 0; d < m; d++) {
        int time = 0;
        for (int q = 0; q < n; q++) {
            if (q == p[d] - 1)
                time += x[d];
            else
                time += t[q];
        }
        cout << time << endl;
    }

    return 0;
}