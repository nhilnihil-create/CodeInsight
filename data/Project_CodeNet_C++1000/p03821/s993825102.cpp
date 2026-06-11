#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N;
    cin >> N;
    vector<ll> a(N), b(N);
    rep(i, N) cin >> a[i] >> b[i];
    ll ans = 0;
    for(int i = N-1; i >= 0; i--){
        a[i] += ans;
        if(a[i] % b[i] == 0) continue;
        else{
            ll v = a[i] / b[i];
            ans += (b[i] * (v+1) - a[i]);
        }
    }
    cout << ans << endl;
    return 0;
}