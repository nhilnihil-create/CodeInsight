#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, t; cin >> k >> t;
    int sum = 0;
    int maxa = 0;
    for (int i=0; i<t; ++i) {
        int a; cin >> a;
        sum += a;
        maxa = max(maxa, a);
    }
    cout << max(0, maxa - (sum - maxa) - 1) << endl;
}