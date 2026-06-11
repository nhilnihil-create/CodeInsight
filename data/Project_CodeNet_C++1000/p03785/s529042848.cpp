#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200005;
const int INF = 1001001001;
const int MOD = 1000000007;

int main(){
    int N, C, K;
    cin >> N >> C >> K;

    vector<int> T(N);
    for (auto &i : T) cin >> i;

    sort(T.begin(), T.end());

    ll ans = 1;
    int time = T[0], num = 1;
    for (int i = 1; i < N; ++i) {
        if (num < C && T[i] <= time + K) {
            num++;
        } else {
            ans++;
            time = T[i];
            num = 1;
        }
    }

    cout << ans << endl;
}