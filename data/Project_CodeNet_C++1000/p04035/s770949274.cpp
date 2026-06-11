#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;


int main(){
    ll n, l;
    cin >> n >> l;
    ll a[n];
    rep(i, n) cin >> a[i];
    ll key = 0;
    bool flag = false;
    rep(i, n - 1){
        if (a[i] + a[i + 1] >= l){
            key = i;
            flag = true;
            break;
        }
    }
    if (flag){
        cout << "Possible" << endl;
        rep(i, key){
            cout << i + 1 << endl;
        }
        for(int j = n - 2; j >= key; j--){
            cout << j + 1 << endl;
        }
    }
    else cout << "Impossible" << endl;
}