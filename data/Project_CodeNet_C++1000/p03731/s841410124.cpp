#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ll N, T; cin >> N >> T;
    vector<ll> t(N);
    for(int i = 0; i < N; i++) cin >> t[i];

    ll sum = T;
    for(int i = 1; i < N; i++){
        ll tmp = abs(t[i] - t[i - 1]);
        if(tmp < T){
            sum += tmp;
        }else{
            sum += T;
        }
    }
    cout << sum << endl;
}
