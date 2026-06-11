#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 1000000010;
const ll MOD = 1000000007;
const double PI = acos(-1);

int main() {
    int N; cin >> N;
    string S; cin >> S;
    int ans = 0;
    int x = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'I') x++;
        if (S[i] == 'D') x--;
        chmax(ans, x);
    }

    cout << ans << endl;
    return 0;
}