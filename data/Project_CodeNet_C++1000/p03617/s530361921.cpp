#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long q, h, s, d, n;
    cin >>q >>h >>s >>d >>n;
    long long min1 = min({4*q,2*h,s});
    long long min2 = min({min1*2,d});

    long long ans = min2 * (n/2);
    ans += (n%2==0) ? 0 : min1;
    cout << ans << endl;
    return 0;
}