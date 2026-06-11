#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    int n , x;
    cin >> n >> x;
    ll count = 0;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(a[0] > x){
        count += a[0] - x;
        a[0] = x;
    }
    for(int i = 1; i < n; i++){
        if(a[i] + a[i - 1] > x){
            count += a[i] + a[i - 1] - x;
            a[i] -= a[i] + a[i - 1] - x;
        }
    }
    cout << count << endl;
    return 0;
}
