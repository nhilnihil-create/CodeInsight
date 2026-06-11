#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll A, B, C, D;
int main() {
    cin >> A >> B >> C >> D;
    if (B < C || D < A) {
        cout << 0 << endl;
        return 0;
    }
    
    if (A <= C) {
        cout << min(abs(C - B), abs(D - C)) << endl;
    } else {
        cout << min(abs(A - D), abs(A - B)) << endl;
    }
}