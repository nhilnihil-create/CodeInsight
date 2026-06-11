#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7, MAX_N = 1e5;
int N, M;
ll x[MAX_N], y[MAX_N];

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++) cin >> x[i];
    for(int i=0;i<M;i++) cin >> y[i];

    ll sum_x = 0, sum_y = 0;
    for(int i=0;i<N;i++){
        sum_x += i * x[i] - (N-i-1) * x[i];
        sum_x %= MOD;
    }
    for(int i=0;i<M;i++){
        sum_y += i * y[i] - (M-i-1) * y[i];
        sum_y %= MOD;
    }

    cout << sum_x * sum_y % MOD << endl;
    return 0;
}
