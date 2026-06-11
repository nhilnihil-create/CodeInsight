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
    ll sum = 0;
    ll ans[2] = {0, 0};
    for(int j = 0; j < 2; j++){
        sum = 0;
        for(int i = 0; i < n; i++){
            sum += a[i];
            if((i + j)%2 == 0){
                if(sum <= 0){
                    ans[j] += 1 - sum;
                    sum = 1;
                }
            }
            else{
                if(sum >= 0){
                    ans[j] += 1 + sum;
                    sum = -1;
                }
            }
        }
    }
    cout << min(ans[0], ans[1]) << endl;
}