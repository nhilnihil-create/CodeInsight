#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using Graph = vector<vector<pii>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<bool> exist(100000);
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        A--;
        if (exist[A])
            cnt++;
        else
            exist[A] = true;
    }

    cnt += cnt % 2;
    cout << N - cnt << endl;

    return 0;
}
