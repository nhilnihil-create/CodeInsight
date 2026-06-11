#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int main() {
    string S;
    cin >> S;

    int cnt = 0;
    char cur = 'A';
    rep(i, S.size()) {
        if (cur != S[i]) {
            cur = S[i];
            cnt++;
        }
    }

    cout << (cnt - 1) << endl;
}