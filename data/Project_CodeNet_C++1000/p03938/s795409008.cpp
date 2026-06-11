#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    ll n; cin >> n;
    vector<ll> p(n), a(n), b(n), sum(n);

    ll count = 9e8;
    rep(i,n){
        cin >> p[i]; p[i]--;
        sum[p[i]] = count; count++;
    }

    a[0] = 1; b[0] = sum[0]-1;
    rep(i,n-1){
        if(sum[i+1] < sum[i]){ a[i+1] = a[i]+1; b[i+1] = sum[i+1]-a[i+1]; }
        else{ b[i+1] = b[i]-1; a[i+1] = sum[i+1]-b[i+1]; }
    }
    
    rep(i,n) cout << a[i] << " ";
    cout << endl;
    rep(i,n) cout << b[i] << " ";
    return 0;
}