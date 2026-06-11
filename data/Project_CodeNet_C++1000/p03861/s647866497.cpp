#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
typedef long long ll;
typedef long double ld;

int main() {
    ll  a,b,x;
    cin >> a >> b >> x;
    ll ans = 0;
    if(a % x == 0) ans++;
    a = a - (a % x);
    b = b - (b % x);
    ans += (b - a) / x;
    
    cout << ans << endl;
}
