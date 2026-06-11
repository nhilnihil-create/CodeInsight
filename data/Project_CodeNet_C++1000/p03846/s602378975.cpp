#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    rep(i, n){
        int b;
        cin >> b;
        a[b]++;
    }

    ll ans = 1;
    int mod = 1000000007;
    if(n % 2 == 0){
        rep(i, n){
            if(i % 2 == 0){
                if(a[i] > 0)ans = 0;
            }else{
                if(a[i] == 2){
                    ans *= 2;
                    ans %= mod;
                }
                else ans = 0;
            }
        }
    }else{
        rep(i, n){
            if(i % 2 == 1){
                if(a[i] > 0)ans = 0;
            }else{
                if(i == 0){
                    if(a[i] != 1)ans = 0;
                }else if(i % 2 == 0){
                    if(a[i] == 2){
                        ans *= 2;
                        ans %= mod;
                    }
                }else ans = 0;
            }
        }
    }
    cout << ans << endl;
}