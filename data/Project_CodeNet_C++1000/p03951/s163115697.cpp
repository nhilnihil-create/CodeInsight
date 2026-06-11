#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(long long N, std::string s, std::string t) {
    rep(i, N) {
        string subs = s.substr(i);
        if (t.find(subs) != t.npos) {
            cout << (s.substr(0, N - subs.length()) + t).length() << endl;
            return;
        }
    }
    cout << (s + t).length() << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::string s;
    std::cin >> s;
    std::string t;
    std::cin >> t;
    solve(N, s, t);
    return 0;
}
