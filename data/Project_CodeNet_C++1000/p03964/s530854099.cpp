#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    long n, t, a, voteT = 1, voteA = 1, temp, ans;
    cin >> n;
    rep(i, n) {
        cin >> t >> a;
        temp = max(voteT / t + ((voteT % t)? 1 : 0), voteA / a + ((voteA % a)? 1 : 0));
        voteT = temp * t;
        voteA = temp * a;
    }
    ans = voteT + voteA;
    cout << ans << endl;
}