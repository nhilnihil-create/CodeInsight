#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > x){
            ans += a[i]-x;
            a[i] = x;
        }
    }
    for(int i = 0; i < n-1; i++){
        if(a[i]+a[i+1] > x){
            ans += a[i]+a[i+1]-x;
            a[i+1] -= a[i]+a[i+1]-x;
        }
    }

    cout << ans << endl;
    return 0;
}