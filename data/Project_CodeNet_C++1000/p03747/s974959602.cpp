#include <bits/stdc++.h>

typedef long long int ll;
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;


int main(){
    int n, l, t;
    cin >> n >> l >> t;
    vector<int> x(n), w(n);
    rep(i, n) cin >> x[i] >> w[i];
    
    ll cnt = 0;
    rep(i, n){
        if(w[i] == 1) x[i] += t;
        else          x[i] -= t;

        cnt += x[i] / l;
        x[i] %= l;
        if(x[i] < 0){
            x[i] += l;
            cnt--;
        }
    }
    sort(x.begin(), x.end());

    cnt = (cnt%n+n)%n;
    rep(i, n) cout << x[(i+cnt)%n] << endl;

    return 0;
}
