#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

ll n;

ll add(ll x, ll y){
    if(y < 0){
        return (x + y + n) % n;
    }else{
        return (x + y) % n;
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n; cin >> n;
    ll a[n];
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
    ll sumn = n * (n + 1) / 2;
    if(sum % sumn != 0){
        cout << "NO" << endl;
        return 0;
    }
    ll ops = sum / sumn;
    ll d[n];
    for(int i=0;i<n-1;i++){
        d[i] = a[i+1] - a[i];
    }
    d[n-1] = a[0] - a[n-1];
    // finally, all d is 0
    for(int i=0;i<n;i++){
        if((ops - d[i]) < 0 || (ops - d[i]) % n != 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}