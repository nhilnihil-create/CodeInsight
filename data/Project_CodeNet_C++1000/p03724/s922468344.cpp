#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> c(n+1,0);
    rep(i, 0, m){
        ll a, b;
        cin >> a >> b;
        c[a]++;
        c[b]++;
    }

    rep(i, 1, n+1){
        if(c[i]%2 == 1){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}