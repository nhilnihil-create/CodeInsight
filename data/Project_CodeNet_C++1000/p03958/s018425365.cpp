#include <bits/stdc++.h>
using namespace std;

#define REP(i, start, count) for(int i=(start); i<(int)(count); ++i)
#define rep(i, count) REP(i, 0, count)
#define ALLOF(c) (c).begin(), (c).end()

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> veci;
typedef vector<long long> vecll;
typedef vector<unsigned long long> vecull;

int K, T;

int main(void) {
    cin >> K >> T;
    veci a(T);
    rep(i, T) {
        cin >> a[i];
    }

    sort(ALLOF(a), std::greater<int>());

    int rest = a[0];
    for(int i = 1; i < T; ++i) {
        rest -= a[i];
        if (rest <= 0) rest = abs(rest);
    }

    cout << max(rest - 1, 0) << endl;
    return 0;
}