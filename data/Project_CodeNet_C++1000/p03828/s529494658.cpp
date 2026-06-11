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
//ll calc_digit(ll N) {
//    ll res = 0;
//    while (N) {
//        ++res;
//        N /= 10;
//    }
//    return res;
//}
//ll sum_digit(ll N) {
//    ll res = 0;
//    while (N) {
//        res += N % 10;
//        N /= 10;
//    }
//    return res;
//}
ll a[9999] = {0};
void prime_factorize(ll n){
    for(int i = 2;i * i <= n;i++){
        if(n % i != 0) continue;
            ll ex = 0;
            while(n % i == 0){
                ++ex;
                n /= i;
            }
        //cout << i << " " << ex << endl;
        a[i] += ex;
    }
    if(n != 1) a[n]++;//cout << n << " " << 1 << endl;
}


int main(){
    int n; cin >> n;
    for(int i = 1;i <= n;i++){
        prime_factorize(i);
    }
    ll ans = 1;
    for(int i = 2;i <= 9999;i++){
        if(a[i] != 0){
            ans *= a[i]+1;
            ans %= MOD;
        }
    }
    cout << ans;
}

