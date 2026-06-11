#include <bits/stdc++.h>
#define INF 1e9
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define FORE(i, a, b) for (int i = (a), e = (b); i < e; ++i)
#define RFORE(i, a, b) for (int i = (b)-1, e = (a); i >= e; --i)
#define ALL(x) (x).begin(), (x).end()
#define SORT(c) sort((c).begin(), (c).end())
#define SORTR(c) sort((c).begin(), (c).end(), greater<int>())
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    // int even = 0;
    int odd = 0;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (tmp % 2 == 1) { ++odd; }
        // if (tmp % 2 == 0) {
        //     ++even;
        // } else {
        //     ++odd;
        // }
    }
    // even += odd / 2;
    // even %= 2;
    // odd %= 2;
    if (odd % 2 == 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}
