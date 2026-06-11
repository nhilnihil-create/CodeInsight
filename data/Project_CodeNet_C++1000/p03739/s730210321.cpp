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
    vector<ll> a(n);
    rep(i, n)cin >> a[i];

    ll sum1 = 0;
    ll ans1 = 0;
    for(int i = 0; i < n; i++){
        sum1 += a[i];
        if(i % 2 == 0){
            if(sum1 >= 0){
                ans1 += sum1 + 1;
                sum1 = -1;
            }
        }else{
            if(sum1 <= 0){
                ans1 += 1 - sum1;
                sum1 = 1;
            }
        }
    }

    ll sum2 = 0;
    ll ans2 = 0;
    for(int i = 0; i < n; i++){
        sum2 += a[i];
        if(i % 2 == 1){
            if(sum2 >= 0){
                ans2 += sum2 + 1;
                sum2 = -1;
            }
        }else{
            if(sum2 <= 0){
                ans2 += 1 - sum2;
                sum2 = 1;
            }
        }
    }
    cout << min(ans1, ans2) << endl;
}