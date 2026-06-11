#include <bits/stdc++.h>
using namespace std;

long count(int sign0, vector<long> a, int n) {
    long count = 0;
    long total = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
            if ((total + a.at(i)) * sign0 < 0) total += a.at(i);
            else {
                count += abs(total + a.at(i)) + 1;
                total = -1 * sign0;
            }
        } else if (i % 2 == 0) {
            if ((total + a.at(i)) * sign0 > 0) total += a.at(i);
            else {
                count += abs(total + a.at(i)) + 1;
                total = sign0;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<long> a(n);
    for (int i = 0; i < n; i++) cin >> a.at(i);

    long plus = count(1, a, n);
    long minus = count(-1, a, n);
    cout << min(plus, minus) << endl;
}
