#include <bits/stdc++.h>
#define rep(i,n) for(long long int i = 0; i < n; i++)
#define _rep(i,m,n) for(long long int i = m; i < n; i++)
#define print(n) std::cout << n << std::endl
#define _print(n) std::cout << n
using namespace std;
typedef long long ll;
const int N = 1000000;
const ll mod = 1000000007;

int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll a0_plus_sum = 0;
    ll a0_plus_count = 0;
    ll a0_minus_sum = 0;
    ll a0_minus_count = 0;

    //a0 = plus
    for(int i = 0; i < n; i++){
        if(i % 2 == 1){
            if(a0_plus_sum + a[i] < 0){
                a0_plus_sum += a[i];
            }else{
                a0_plus_count += 1 + (a0_plus_sum + a[i]);
                a0_plus_sum = -1;
                }
        }else if(i % 2 == 0){
            if(a0_plus_sum + a[i] > 0){
                a0_plus_sum += a[i];
            }else{
                a0_plus_count += 1 - (a0_plus_sum + a[i]);
                a0_plus_sum = 1;
                }
        }
    }

    //a0 = minus
    for(int i = 0; i < n; i++){
        if(i % 2 == 1){
            if(a0_minus_sum + a[i] > 0){
                a0_minus_sum += a[i];
            }else{
                a0_minus_count += -(a0_minus_sum + a[i]) + 1;
                a0_minus_sum = 1;
                }
        }else if(i % 2 == 0){
            if(a0_minus_sum + a[i] < 0){
                a0_minus_sum += a[i];
            }else{
                a0_minus_count += (a0_minus_sum + a[i]) + 1;
                a0_minus_sum = -1;
                }
        }
    }
    print(min(a0_minus_count,a0_plus_count));
}