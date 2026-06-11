#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int total = a + b + c;

    int maxNum = a;
    maxNum = max(maxNum, b);
    maxNum = max(maxNum, c);

    cout << total - maxNum << endl;

    return 0;
}