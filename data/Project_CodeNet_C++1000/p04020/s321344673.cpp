#include<bits/stdc++.h> 
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;
    rep(i, n){
        ans += a[i] / 2;
        if (i != n - 1 && a[i] % 2 && a[i + 1]){
            a[i + 1]--;
            ans++;
        }
    }
    cout << ans << endl;
}