#include <bits/stdc++.h>
#define INF 1e+9
#define debug(x) cerr << #x << ": " << x << "\n";
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
    ll K;
    cin >> K;

    int N = 50;
    ll a = K / N;
    ll b = K % N;

    debug(a);debug(b);

    ll res[N];
    for(int i = 0; i < N; i++){
        res[i] = i;
    }
    for(ll i = 0; i < b; i++){
        res[i] += N+1;
        for(int j = 0; j < N; j++){
            res[j] += -1;
        }
    }

    for(auto& x: res) x += a;

    cout << N << "\n";
    cout << res[0];
    for(int i = 1; i < N; i++){
        cout << " " << res[i];
    }
    cout << endl;
    return 0;
}