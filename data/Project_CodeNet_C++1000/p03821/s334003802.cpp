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
    vector<int>a(n);
    vector<int>b(n);
    rep(i, 0, n){
        cin >> a[i] >> b[i];
    }
    ll ans = 0;
    for(int i = n-1; i >= 0; i--){
        ll tmp = (a[i]+ans) % b[i];
        if(tmp == 0) ans+=tmp;
        else ans+= b[i]-tmp;
    }
    cout << ans << endl;
    return 0;
}
