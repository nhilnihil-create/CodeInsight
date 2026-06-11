#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N;
    cin >> N;
    vector<ll> vec(N);
    rep(i,N){
        cin >> vec[i];
    }
    ll part_sum1 = 0;
    ll part_sum2 = 0;
    ll ans1 = 0;
    ll ans2 = 0;
    ll ans = 0;
    if (vec[0] <= 0){
        part_sum1 = 1;
        ans1 = 1 - vec[0];
    }
    else{
        part_sum1 = vec[0];
    }
    for (ll i = 1; i <= N - 1; i++){
        if (i % 2 == 1){
            if (part_sum1 + vec[i] >= 0){
                ans1 += part_sum1 + vec[i] + 1;
                part_sum1 = -1;
            }
            else{
                part_sum1 += vec[i];
            }
        }
        else{
            if (part_sum1 + vec[i] <= 0){
                ans1 += 1 - (part_sum1 + vec[i]);
                part_sum1 = 1;
            }
            else{
                part_sum1 += vec[i];
            }
        }
    }
    if (vec[0] >= 0){
        part_sum2 = -1;
        ans2 = 1 + vec[0];
    }
    else{
        part_sum2 = vec[0];
    }
    for (ll i = 1; i <= N - 1; i++){
        if (i % 2 == 1){
            if (part_sum2 + vec[i] <= 0){
                ans2 += 1 - (part_sum2 + vec[i]);
                part_sum2 = 1;
            }
            else{
                part_sum2 += vec[i];
            }
        }
        else{
            if (part_sum2 + vec[i] >= 0){
                ans2 += 1 + part_sum2 + vec[i];
                part_sum2 = -1;
            }
            else{
                part_sum2 += vec[i];
            }
        }
    }
    ans = min(ans1, ans2);
    cout << ans << endl;
}
