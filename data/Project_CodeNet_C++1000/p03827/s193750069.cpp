#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    ll N;
    string S;
    cin >> N >> S;
    int ans = 0;
    int tmp = 0;
    rep(i,N) {
        if (S.at(i) == 'I') ++tmp;
        else --tmp;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}

