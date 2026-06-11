#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int mod = 1e9 + 7;

int main() {
    int N; cin >> N;
    vector<ll> cnt(N+1);
    for (int i = 2; i <= N; i++){
        int now = i;
        for (int j = 2; j*j <= i; j++){
            while(now % j == 0){
                now /= j;
                cnt[j]++;
            }
        }
        if(now != 1){
            cnt[now]++;
        }
    }

    ll ans = 1;
    for (int i = 2; i <= N; i++){
        ans *= cnt[i]+1;
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}