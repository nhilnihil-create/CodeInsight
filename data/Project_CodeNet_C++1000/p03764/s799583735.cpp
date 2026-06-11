#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const int MAX = 1e5+10;
const int MOD = 1e9+7;

int main(){
    int N,M; cin >> N >> M;
    vector<ll> x(N), y(M);
    for(int i=0;i<N;i++) cin >> x[i];
    for(int i=0;i<M;i++) cin >> y[i];

    ll x_sum = 0ll;
    ll y_sum = 0ll;
    for(int i=1;i<N;i++){
        ll x_tmp = x[i] - x[i-1];
        x_sum += x_tmp * i * (N-i);
        x_sum %= MOD;
    }

    for(int j=1;j<M;j++){
        ll y_tmp = y[j] - y[j-1];
        y_sum += y_tmp * j * (M-j);
        y_sum %= MOD;
    }

    cout << (x_sum * y_sum) % MOD << endl;

    return 0;
}