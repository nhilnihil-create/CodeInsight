#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
typedef long long ll;
typedef long double ld;

int main(){
    ll ans = 0;
    ll N, C, K;
    cin >> N >> C >> K;
    vector<ll> T(N + 1,0);
    for(int i = 0; i < N; i++) cin >> T[i];
    T[N] = 10000000000;
    sort(T.begin(),T.end());
    int cnt = 1;
    int tmp = T[0];
    for (int i = 1; i <= N; i++) {
        cnt++;
        if (cnt > C || T[i] - tmp > K) {
            cnt = 1;
            tmp = T[i];
            ans++;
            }
    }

    cout << ans << endl;

}
