#include <bits/stdc++.h>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>  // is_any_of
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
    string S;
    cin >> S;

    int N = S.size();
    int M = N - 1;

    ll ans = 0;
    for (int bit = 0; bit < (1 << M); bit++) {
        string s = S;
        for (int i = 0; i < M; i++) {
            if (bit & (1 << i)) {
                s.insert(M - i, "+");
            }
        }
        vector<string> T;
        boost::algorithm::split(T, s, boost::is_any_of("+"));
        for (auto t : T) {
            ans += stoll(t);
        }
    }
    cout << ans << endl;

    return 0;
}