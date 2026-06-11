#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

typedef long long ll;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << max(0, min(B, D) - max(A, C)) << "\n";
}