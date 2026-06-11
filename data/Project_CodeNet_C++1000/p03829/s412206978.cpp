#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <vector>
#define REP(i, n) for(int i = 0; i < (n); ++i)
typedef long long ll;
const ll MOD = 1e9+7;
using namespace std;

int main(){
    int n, a, b; cin >> n >> a >> b;
    ll ans = 0;
    vector<int> x(n);
    REP(i, n){
        cin >> x[i];
        if(i) ans += min((ll)b, (ll)(x[i]-x[i-1]) *a);
    }
    cout << ans << endl;
    return 0;
}
