#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 100000000000000000

int main() {
    string s;
    cin >> s;
    vector<ll> A(26);
    rep(i, s.size()) { A[s[i] - 'a']++; }

    rep(i, A.size()) { A[i] -= 1; }

    ll sum = 0;

    rep(i, 26) {
        if (A[i] == -1)
            continue;
        else if (A[i] == 1)
            sum += 1;
        else
            sum += ((A[i] + 1) * A[i] / 2);
    }

    ll whole = s.size() * (s.size() - 1) / 2;
    cout << whole - sum + 1 << endl;
}