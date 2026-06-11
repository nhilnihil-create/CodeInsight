#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<ll>a(3*n);
    rep(i,n*3)cin >> a[i];
    ll ans = 0;
    sort(all(a));
    reverse(all(a));
    rep(i,n)a.pop_back();
    for(int i = 0;i < n;i++){
        ans += a[2*i+1];
        //cout << a[2*i] << endl;
    }
    cout << ans << endl;
    return 0;
}