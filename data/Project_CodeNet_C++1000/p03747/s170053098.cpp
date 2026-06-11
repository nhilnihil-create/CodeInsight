#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll n,l,t;
    cin >> n >> l >> t;
    ll x[n], y[n];
    int w[n];
    for(int i=0;i<n;i++){
        cin >> x[i] >> w[i];
        if(w[i] == 1){
            y[i] = (x[i] + t) % l;
        }else{
            y[i] = (((x[i] - t) % l) + l) % l;
        }
    }
    sort(y, y+n);

    ll i0 = 0LL;
    for(int i=0;i<n;i++){
        if(w[i] == 1){
            if(l-x[i] > t) continue;
            i0 -= (t-(l-x[i])+l-1)/l;
        }else{
            if(x[i] > t) continue;
            i0 += (t-x[i]+l-1)/l;
        }
    }

    i0 = (i0 % n) + n;
    ll ans[n];
    for(int i=0;i<n;i++){
        ans[(i0+i)%n] = y[i];
    }
    for(int i=0;i<n;i++){
        cout << ans[i] << endl;
    }
}