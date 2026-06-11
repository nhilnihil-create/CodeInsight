#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll sum = 0, ans = 0, ans2 = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
        if(i%2 == 0){
            if(sum <= 0){
                ans += 1 - sum;
                sum = 1;
            }
        }
        else{
            if(sum >= 0){
                ans += 1 + sum;
                sum = -1;
            }
        }
    }
    sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
        if(i%2 == 0){
            if(sum >= 0){
                ans2 += 1 + sum;
                sum = -1;
            }
        }
        else{
            if(sum <= 0){
                ans2 += 1 - sum;
                sum = 1;
            }
        }
    }
    cout << min(ans, ans2) << endl;
}