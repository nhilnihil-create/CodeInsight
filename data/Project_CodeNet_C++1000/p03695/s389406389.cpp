#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, N) for (ll i = 0; i < (N); i++)
#define For(i, a, b) for (ll i = (a); i < (b); i++)
#define all(A) (A).begin(), (A).end()

int main(){
    int N;
    cin >> N;
    int A[9];
    rep(i, 9) A[i] = 0;
    rep(i, N) {
        int tmp;
        cin >> tmp;
        tmp = min(tmp / 400, 8);
        A[tmp]++;
    }
    int ans = 0;
    rep(i, 8) {
        if (A[i] >= 1) ans++;
    }
    int min_ans;
    min_ans = max(ans, 1);
    int max_ans;
    max_ans = ans + A[8];

    cout << min_ans << " " << max_ans << endl;

    return 0;
}
