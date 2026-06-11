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
    vector<ll> a(3 * N);
    rep(i, 3*N) cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());
    rep(i, N) a.pop_back();
    ll ans = 0;
    rep(i, 2*N){
        if(i % 2 == 1){
            ans += a[i];
        }
    }
    cout << ans << endl;
    return 0;
}