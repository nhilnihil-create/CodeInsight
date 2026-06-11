#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int mod = 1e9+7;

int main(){
    int N,M;
    cin >> N >> M;
    vector<ll> x(N+1), y(M+1);

    for(int i=1;i<=N;i++){
        cin >> x[i];
    }
    for(int i=1;i<=M;i++){
        cin >> y[i];
    }

    ll sum_x = 0ll;
    ll sum_y = 0ll;
    for(int i=1;i<=N;i++){
        (sum_x += ( (i-1)*x[i] - (N-i)*x[i] + mod ) %mod ) %=mod;
    }
    for(int i=1;i<=M;i++){
        (sum_y += ( (i-1)*y[i] - (M-i)*y[i] + mod ) %mod ) %=mod;
    }

    cout << sum_x * sum_y % mod << endl;


    return 0;
}