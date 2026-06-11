#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (ll i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    ll N;
    cin >> N;
    int cnt = 0;
    int ni = 0;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    rep(i, N){
        a[i]%=4;
        if(!a[i]) cnt++;
        else if(a[i]==2) ni++;
    }
    cnt+=ni/2;
    if(N%3==0) cout << (N/3<=cnt? "Yes": "No") << endl;
    else cout << (N/2<=cnt? "Yes": "No") << endl;
    return 0;
}
