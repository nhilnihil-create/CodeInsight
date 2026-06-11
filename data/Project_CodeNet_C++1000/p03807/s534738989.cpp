#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    int odd_cnt = 0;
    rep(i, N) {
        int A;
        cin >> A;
        odd_cnt += A % 2;
    }
    if (odd_cnt % 2) cout << "NO\n";
    else cout << "YES\n";
    return 0;
}
