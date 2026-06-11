#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int> mp;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        mp[A[i]] = i;
    }

    sort(A.begin(), A.end());
    int cnt = 0;
    vector<bool> mov(N);
    for (int i = 0; i < N; ++i)
        if ((mp[A[i]] ^ i) & 1)
            cnt++;

    cout << cnt / 2 << endl;

    return 0;
}
