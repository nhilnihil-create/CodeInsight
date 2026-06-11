#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    cin >> N;
    ll ans =0;
    ll remain =0;
    for(int i=0;i<N;i++){
        ll a;
        cin >> a;
        if(remain>0 && a>0){
            ans++;
            a--;
        }
        ans += (a/2);
        remain = a%2;

    }
    cout << ans << endl;

    return 0;
}