#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
    ll n;
    cin >> n;
    ll a[n];
    ll sum = 0;
    rep(i,n) {
        cin >> a[i];
        sum += a[i];
    }
    ll m = n*(n+1)/2;
    vector<ll> b;
    rep(i,n) b.push_back(a[(i+1)%n]-a[i]);
    sort(b.begin(),b.end(),greater<ll>());
    ll s = 0;
    rep(i,n){
        if((b[0]-b[i]) % n){
            cout << "NO" << endl;
            return 0;
        } else {
            s += (b[0]-b[i])/n;
        }
    }
    if(b[0] == s && sum >= s*m && ((sum-s*m)%(n*m)) == 0)  cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}