#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;

int main(void){
    ll n, a[100010];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    ll ans = 0, mn = 2;
    ans += a[0] - 1;
    //cout << ans << endl;
    for (int i = 1; i < n; i++) {
        if (a[i] == mn) mn++;
        else if (a[i] > mn) ans += (a[i] - 1) / mn;
        //cout << mn << " " << ans << endl;
    }
    
    cout << ans << endl;
}
