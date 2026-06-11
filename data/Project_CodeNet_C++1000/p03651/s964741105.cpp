#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, k, fpb, maxim;
int a[N];

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    maxim = INT_MIN;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        maxim = max(maxim, a[i]);
    }
    fpb = a[1];
    for(int i = 2; i <= n; i++) {
        fpb = gcd(fpb, a[i]);
    }
    if(k > maxim || k % fpb != 0) cout << "IMPOSSIBLE\n";
    else cout << "POSSIBLE\n";
}