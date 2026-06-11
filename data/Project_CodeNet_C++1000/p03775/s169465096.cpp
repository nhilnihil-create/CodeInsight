#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7; //10の9乗

ll F(ll A, ll B) {
    return max(log10(A)+1, log10(B)+1);
}

int main(){
    ll N;
    cin >> N;
    ll min_value = INF;

    for(ll i=1; i * i <= N; i++) {
        if(N % i == 0) {
            ll B = N / i;
            min_value = min(min_value, F(i, B));
        }
    }
    cout << min_value << endl;
}