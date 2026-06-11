#include <bits/stdc++.h>

using namespace std;

const int HUGEI = 2147483647;  // (1 << 31) - 1
const long long HUGEL = 9223372036854775807;  // (1 << 63) - 1
const string ABC = "abcdefghijklmnopqrstuvwxyz";

int main(void) {
    int n;
    vector <int> an;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        an.push_back(a);
    }
    vector <long long> bn;
    bn.push_back((long long) an[0]);
    for (int i = 1; i < n; i++) {
        bn.push_back(bn[i - 1] + (long long) an[i]);
    }
    long long res = HUGEL;
    for (int i = 0; i < n - 1; i++) {
        res = min(res, abs(bn[n - 1] - 2 * bn[i]));
    }
    cout << res << endl;
    return 0;
}
