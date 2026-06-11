#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)

typedef long long Int;

int main() {

    int K, S;
    cin >> K >> S;

    int cnt = 0;

    rep(i,K+1) rep(j,K+1) {
        if (S - i - j >= 0 && S - i - j <= K) cnt++;
    }

    cout << cnt << endl;


    return 0;
}
