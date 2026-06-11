#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<int> A(N); unordered_map<int, int> mp;
    REP(i, 0, N) {
        cin >> A[i]; mp[A[i]] = i;
    }

    sort(ALL(A));

    int ans = 0;
    REP(i, 0, N) {
        if ((i % 2 == 0) != (mp[A[i]] % 2 == 0)) ans++;
    }
    cout << ans / 2 << endl;
    return 0;
}