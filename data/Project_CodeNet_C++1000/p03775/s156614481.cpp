#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;


//void warshall_floyd(int n){
//    for(int k=0;k<n;k++){
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++){
//                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
//            }
//        }
//    }
//}

int calc_digit(long long N) {
    int res = 0;
    while (N) {
        ++res;
        N /= 10;
    }
    return res;
}

int main() {
    ll n; cin >> n;
    int ans = INT_MAX;
    for(ll i = 1;i * i <= n;i++){
        if(n % i == 0){
            ll b = n / i;
            int f = max(calc_digit(i),calc_digit(b));
            ans = min(ans,f);
        }
    }
    cout << ans;
 }

