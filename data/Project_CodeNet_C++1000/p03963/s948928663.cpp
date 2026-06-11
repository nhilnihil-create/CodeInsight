#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int N,K;
    ll ans = 1;
    cin >> N >> K;

    ans *= K;
    rep(i, N-1){
        ans *= K-1;
    }

    cout << ans << endl;

    return 0;
}