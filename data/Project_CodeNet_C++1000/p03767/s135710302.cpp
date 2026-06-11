#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;

int main() {

    int n;
    cin >> n;
    vector<ll>a(n*3);
    rep(i, 0, n*3) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    ll ans =0;
    for (int i = 1; i < n*2 ; i+=2) {
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
    
}

