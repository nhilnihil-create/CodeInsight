#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    string S;
    cin >> S;
    ll sum = 0;
    int n = S.size();
    if (n == 1) sum = stol(S);
    for (int bit = 0; bit < (1<<n-1); bit++) {
        string tmp = S;
        for (int i = 0; i < n-1; ++i) {
            if (bit & (1<<i)) {
                sum += stol(tmp.substr(n-i-1));
                tmp = tmp.erase(n-i-1);
            }
            if (i == n - 2) sum += stol(tmp);
        }
    }
    cout << sum << endl;
}
