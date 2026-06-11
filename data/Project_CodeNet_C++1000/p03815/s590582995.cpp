#include <bits/stdc++.h>
using namespace std;

int main(){
    long long x,ans = 0LL;
    cin >> x;
    long long tmp = x/11LL, tmp2 = x%11LL;
    ans = 2LL * tmp;
    if(0LL < tmp2 && tmp2 <= 6) ans++;
    else if(tmp2 > 6) ans += 2LL;
    cout << ans << endl;
}