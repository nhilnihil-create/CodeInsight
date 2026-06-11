#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

ll factorialMethod(int k){
    ll sum = 1;
    for (int i = 1; i <= k; ++i)
    {
        sum *= i;
        sum %= C;
    }
    return sum;
}

int main(){
    int N, M;
    cin >> N >> M;

    if(abs(N-M) > 1) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = factorialMethod(N) * factorialMethod(M);
    ans %= C;
    if(N == M) ans *= 2;
    ans %= C;

    cout <<  ans << endl;


}