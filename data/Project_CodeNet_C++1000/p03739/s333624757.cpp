#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n), dp1(n), dp2(n);
    rep(i, 0, n) cin >> a[i];
    ll ans1 = 0, ans2 = 0;

    if(a[0] > 0){
        ans2 = a[0] - (-1);
        dp1[0] = a[0];
        dp2[0] = -1;
    }else if(a[0] == 0){
        ans1 = 1;
        ans2 = 1;
        dp1[0] = 1;
        dp2[0] = -1;
    }else{
        ans1 = 1 - a[0];
        dp1[0] = 1;
        dp2[0] = a[0];
    }
    rep(i, 1, n){
        if(dp1[i-1] < 0){
            if(dp1[i-1] + a[i] > 0){
                dp1[i] = dp1[i-1] + a[i];
            }else if(dp1[i-1] + a[i] == 0){
                ans1 += 1;
                dp1[i] = 1;
            }else{
                dp1[i] = 1;
                ans1 += 1 - (dp1[i-1] + a[i]);
            }
        }else{
            if(dp1[i-1] + a[i] < 0){
                dp1[i] = dp1[i-1] + a[i];
            }else if(dp1[i-1] + a[i] == 0){
                ans1 += 1;
                dp1[i] = -1;
            }else{
                dp1[i] = -1;
                ans1 += (dp1[i-1] + a[i]) - (-1);
            }
        }

        
        if(dp2[i-1] < 0){
            if(dp2[i-1] + a[i] > 0){
                dp2[i] = dp2[i-1] + a[i];
            }else if(dp2[i-1] + a[i] == 0){
                ans2 += 1;
                dp2[i] = 1;
            }else{
                dp2[i] = 1;
                ans2 += 1 - (dp2[i-1] + a[i]);
            }
        }else{
            if(dp2[i-1] + a[i] < 0){
                dp2[i] = dp2[i-1] + a[i];
            }else if(dp2[i-1] + a[i] == 0){
                ans2 += 1;
                dp2[i] = -1;
            }else{
                dp2[i] = -1;
                ans2 += (dp2[i-1] + a[i]) - (-1);
            }
        }
    }

    cout << min(ans1, ans2) << endl;
    return 0;
}