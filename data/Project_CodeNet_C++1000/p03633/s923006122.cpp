#include <iostream>
#include <algorithm>

using namespace std;

const long long maxt=1e18+1;
const int maxLen = 105;
long long t[maxLen], ct[maxLen];

long long gcd(long long a, long long b) {
    while (b) {
        long long temp;
        a %= b;
        temp = a;
        a = b;
        b = temp;
    }
    return a;
}

void solve() {
    int n;
    cin >> n;
    long long ans = 0;
    for (int i=0; i < n; ++i) {
        cin >> t[i];
        ct[i] = t[i];
    }
    //НОК(a, b, c) == НОК(НОК(a,b), c)
    //НОД(a, b, c) == НОД(НОД(a,b), c)
    /*for (int i=1; i<n; ++i) {
        ct[i] = gcd(ct[i], ct[i-1]);
    }*/
    //cout << ct[n-1] << endl;
    for (int i=1; i<n; ++i) {
        ct[i] = (ct[i-1] / gcd(t[i], ct[i-1])) * t[i];
    }
    ans = ct[n-1];
    cout << ans;
}

int main() {

	solve();
    return 0;
}
