#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N; cin >> N;
    int four = 0;
    int two = 0;
    int other = 0;
    rep(i, N) {
        int A; cin >> A;
        if (A % 4 == 0) four++;
        else if (A % 2 == 0) two++;
        else other++;
    }

    if ((other <= four && (two == 0 || two > 1))
        || (other + two) - four == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
