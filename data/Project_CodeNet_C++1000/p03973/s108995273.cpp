#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ans = a[0]-1, k = 1;
    for(int i = 1; i < n; i++){
        if(a[i] <= k)   continue;
        if(a[i] == k+1){
            k++;
            continue;
        }
        // a[i] ~ k+1+1まではk+1ずつ減らして良い
        // k+1にしてしまうとk削らないといけなくなるのでダメ
        // (k+1になってしまう1歩手前でa[i]が1になるまでごっそり削るべき)
        // a[i] ~ k+1+1の数はa[i]-(k+1+1)+1ヶあるのでこれをk+1でfloor取ればOK
        ans += (a[i]-(k+1+1)+1+k)/(k+1);
    }
    cout << ans << endl;
    return 0;
}