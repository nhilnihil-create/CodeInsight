#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> a(3*N);
    for(int i=0;i<3*N;i++){
        cin >> a[i];
    }
    sort(a.rbegin(),a.rend());
    ll ans =0;
    for(int i=0;i<2*N;i++){
        if(i%2 ==1){
            ans += a[i];
        }
    }
    cout << ans << endl;
    return 0;
}