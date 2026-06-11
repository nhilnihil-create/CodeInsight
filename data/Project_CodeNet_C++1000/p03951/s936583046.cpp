#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N; string s, t; cin >> N >> s >> t;
    for (int i = 0; i < N; i++) {
        string a = s.substr(i, N - i), b = t.substr(0, N - i);
        if (a == b) {
            cout << 2 * i + (N - i) << endl;
            return 0;
        }
    }
    cout << 2 * N << endl;
    return 0;
}
