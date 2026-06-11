#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define INF 10**9

int main() {
    ll n,x,ans;
    cin >> n >> x;
    vector<ll> A(n);
    rep(i,n){
        cin >> A.at(i);
    }
    if (A.at(0) > x){
        ans = A.at(0)-x;
        A.at(0) = x;
    }
    else{
        ans = 0;
    }
    rep(i,n-1){
        if (A.at(i)+A.at(i+1) > x){
            ans += (A.at(i)+A.at(i+1))-x;
            A.at(i+1) -= ((A.at(i)+A.at(i+1)-x));
        }
    }
    cout << ans << endl;
}