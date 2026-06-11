#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    cout << max(A * B, C * D) << endl;

    return 0;
}