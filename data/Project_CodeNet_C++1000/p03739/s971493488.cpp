#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 1e18, sum = 0, cnt = 0;
    int flag = 1;
    rep(i,n){
        if(flag == 1){
            if(sum + a[i] <= 0){
                cnt += 1-sum-a[i];
                sum = 1;
            }
            else sum += a[i];
        }
        else{
            if(sum + a[i] >= 0){
                cnt += abs(-1-sum-a[i]);
                sum = -1;
            }
            else sum += a[i];
        }
        flag = -flag;
        //cout << sum << endl;
    }
    ans = min(ans, cnt);

    flag = -1, sum = 0, cnt = 0;
    rep(i,n){
        if(flag == 1){
            if(sum + a[i] <= 0){
                cnt += 1-sum-a[i];
                sum = 1;
            }
            else sum += a[i];
        }
        else{
            if(sum + a[i] >= 0){
                cnt += abs(-1-sum-a[i]);
                sum = -1;
            }
            else sum += a[i];
        }
        flag = -flag;
        //cout << sum << endl;
    }
    ans = min(ans, cnt);
    cout << ans << endl;
}