#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    ll N, M; cin >> N >> M;
    if(M <= N*2){
        ll ans = M/2;
        cout << ans << endl;
    } else {
        ll ans = N + ((M - N*2) / 4);
        cout << ans << endl;
    }

    return 0;
}