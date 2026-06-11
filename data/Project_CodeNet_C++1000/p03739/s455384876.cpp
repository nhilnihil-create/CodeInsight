#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    vector<ll> A(n), sum(n);
    rep(i, 0, n) cin >> A[i];

    // sum[0] > 0
    ll cnt1 = 0;
    if(A[0] > 0){
        sum[0] = A[0];
    }else{
        sum[0] = 1;
        cnt1 += abs(1-A[0]);
    }
    rep(i, 1, n){
        if(sum[i-1] > 0){
            if(sum[i-1] + A[i] < 0){
                sum[i] = sum[i-1] + A[i];
            }else{
                sum[i] = -1;
                cnt1 += abs(sum[i-1] + A[i] - (-1));
            }
        }else{
            if(sum[i-1] + A[i] > 0){
                sum[i] = sum[i-1] + A[i];
            }else{
                sum[i] = 1;
                cnt1 += abs(1 - (sum[i-1] + A[i]));
            }

        }
    }

    // sum[0] < 0
    ll cnt2 = 0;
    if(A[0] < 0){
        sum[0] = A[0];
    }else{
        sum[0] = -1;
        cnt2 += abs(A[0]-(-1));
    }
    rep(i, 1, n){
        if(sum[i-1] > 0){
            if(sum[i-1] + A[i] < 0){
                sum[i] = sum[i-1] + A[i];
            }else{
                sum[i] = -1;
                cnt2 += abs(sum[i-1] + A[i] - (-1));
            }
        }else{
            if(sum[i-1] + A[i] > 0){
                sum[i] = sum[i-1] + A[i];
            }else{
                sum[i] = 1;
                cnt2 += abs(1 - (sum[i-1] + A[i]));
            }

        }
    }
    
    cout << min(cnt1, cnt2) << endl;
    return 0;
}