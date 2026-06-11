#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
#define pll pair<ll, ll>

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int N = s.size();
    int K;
    cin >> K;
    vector<int> A(N, 0);
    rep(i, N) { A[i] = 26 - (s[i] - 'a'); }
    rep(i, N) {
        if (s[i] == 'a' && i != N-1)
            continue;
        if (K - A[i] >= 0) {
            s[i] = 'a';
            K -= A[i];
            A[i] = 26;
            if (K == 0)
                break;
        }
    }

    if (K > 0) {
        if (K > A[N - 1]) {
            int n = K - A[N - 1];
            s[N - 1] = (char)((n % 26) + 'a');
        } else {
            int last = s[N - 1] - 'a';
            s[N - 1] = (char)(last + K + 'a');
        }
    }

    cout << s << endl;
}