#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int g;
	cin >> g;
	int MA = g;
    if (g == k) {
        cout << "POSSIBLE" << endl;
        return 0;
    }
    for (int i=1; i<n; i++) {
        int num; cin >> num;
        if (num == k) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
		g = __gcd(g, num);
		MA = max(MA, num);
    }
    int maxd = MA - g;
    if (maxd < k) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    if (k%g != 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << "POSSIBLE" << endl;
}