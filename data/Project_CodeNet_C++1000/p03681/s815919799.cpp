#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
typedef long long ll;
typedef long double ld;

ll factorial(ll N){
    ll ans = 1;
    for(int i = 1; i <= N; i++){
        ans =  (ans * i) % MOD;
    }
    return ans;
}

int main() {
    ll N, M;
    cin >> N >> M;
    ll ans = 0;
    if(abs(N - M) > 1){
        cout << 0 << endl;
        return 0;
    }

    if(N == M){
        ans = factorial(N) * factorial(M) * 2 % MOD;
    }else{
        ans = factorial(N) * factorial(M) % MOD;
    }

    cout << ans << endl;

}
